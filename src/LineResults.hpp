#pragma once

#include <cmath>
#include <vector>

#include "GeoTypes.hpp"
#include "PointResults.hpp"

class LineResults
{
    
    public:
    
        LineResults(Line& line, Plane& plane) : ln(line), pl(plane)
        {
            ln = line;
            pl = plane;
            rel_pos = CheckRelativePosition();
            
            if(rel_pos != PERPENDICULAR) RenderPSPoints();
        }
        
        Line& ProjOnPlane()
        {
            BuildLineGivenTwoPoints(pj_points[0], pj_points[1], pjL);
            return pjL;
        }

        Line& Symmetric()
        {
            buildLineGivenTwoPoints(sm_points[0], sm_points[1], smL);
            return smL;
        }

        void BuildLineGivenTwoPoints(Coordinates& p1, Coordinates& p2, Line& line)
        {
            line.p.x = p1.x;
            line.p.y = p1.y;
            line.p.z = p1.z;
            line.d.x = p2.x - p1.x;
            line.d.y = p2.y - p1.y;
            line.d.z = p2.z - p1.z;
        }
        
        void RenderPSPoints()
        {
            // Using t = 0 (this is the given point on the line itself)
            PointResults<Plane> rp1(ln.p, pl);
                
            // Using t = 1 to render a second point p2 on the Line
            Coordinates p2 = {
                ln.p.x + ln.d.x,
                ln.p.y + ln.d.y,
                ln.p.z + ln.d.z
            };
                
            PointResults<Plane> rp2(p2, pl);
            
            // Store the points projections on the plan into a vector
            pj_points.push_back(rp1.projOnPlane());
            pj_points.push_back(rp2.projOnPlane());

            // Store the symmetric points into a vector
            sm_points.push_back(rp1.symmetric());
            sm_points.push_back(rp2.symmetric());
        }
        
        RelativePosition CheckRelativePosition()
        {
            const double escalar_product = (ln.d.x)*(pl.n.x) + (ln.d.y)*(pl.n.y) + (ln.d.z)*(pl.n.z);
            const Coordinates vectorial_product
            {
                (ln.d.y)*(pl.n.z) - (ln.d.z)*(pl.n.y),
                (ln.d.z)*(pl.n.x) - (ln.d.x)*(pl.n.z),
                (ln.d.x)*(pl.n.y) - (ln.d.y)*(pl.n.x)
            };
            
            if(escalar_product == 0) return PARALLEL;
            else if (vectorial_product == NULL_VECTOR) return PERPENDICULAR;
            else return OBLIQUE;
        }
        
        RelativePosition RelPos()
        {
            return rel_pos;
        }
        
    private:
    
        Plane& pl;
        Line& ln, pjL, smL;
        RelativePosition rel_pos;
        std::vector<Coordinates> pj_points;
        std::vector<Coordinates> sm_points;
};