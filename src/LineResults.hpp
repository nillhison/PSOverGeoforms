#pragma once

#include <cmath>
#include <vector>

#include "GeoTypes.hpp"
#include "PointResults.hpp"

class LineResults
{
    
    public:
    
        LineResults(Line& line, Plane& plane) : m_line(line), pl(plane)
        {
            m_line = line;
            pl = plane;
            rel_pos = CheckRelativePosition();
            
            if(rel_pos != PERPENDICULAR) RenderPSPoints();
        }
        
        Line& ProjOnPlane()
        {
            BuildLineGivenTwoPoints(pj_points[0], pj_points[1], m_projection);
            return m_projection;
        }

        Line& Symmetric()
        {
            buildLineGivenTwoPoints(sm_points[0], sm_points[1], m_symmetric);
            return m_symmetric;
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
            PointResults<Plane> rp1(m_line.p, pl);
                
            // Using t = 1 to render a second point p2 on the Line
            Coordinates p2 = {
                m_line.p.x + m_line.d.x,
                m_line.p.y + m_line.d.y,
                m_line.p.z + m_line.d.z
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
            const double escalar_product = (m_line.d.x)*(pl.n.x) + (m_line.d.y)*(pl.n.y) + (m_line.d.z)*(pl.n.z);
            const Coordinates vectorial_product
            {
                (m_line.d.y)*(pl.n.z) - (m_line.d.z)*(pl.n.y),
                (m_line.d.z)*(pl.n.x) - (m_line.d.x)*(pl.n.z),
                (m_line.d.x)*(pl.n.y) - (m_line.d.y)*(pl.n.x)
            };
            
            if(escalar_product == 0) return PARALLEL;
            else if (vectorial_product == NULL_VECTOR) return PERPENDICULAR;
            else return OBLIQUE;
        }
        
        RelativePosition RelPos()
        {
            return relPos;
        }
        
    private:
    
        Plane& pl;
        Line& m_line, m_projection, m_symmetric;
        RelativePosition relPos;
        std::vector<Coordinates> pj_points;
        std::vector<Coordinates> sm_points;
};