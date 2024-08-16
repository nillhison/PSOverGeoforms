#pragma once

#include <cmath>
#include <vector>

#include "GeoTypes.hpp"
#include "PointResults.hpp"

class LineResults {
    
    public:
    
        LineResults(Line& line, Plane& plane) : ln(line), pl(plane) {
            ln = line;
            pl = plane;
            
            relPos = checkRelativePosition();
            
            if(relPos != PERPENDICULAR) renderPSPoints();
        }
        
        Line& projOnPlane() {
            buildLineGivenTwoPoints(pjPoints[0], pjPoints[1], pjL);
            return pjL;
        }

        Line& symmetric() {
            buildLineGivenTwoPoints(smPoints[0], smPoints[1], smL);
            return smL;
        }

        void buildLineGivenTwoPoints(Coordinates& p1, Coordinates& p2, Line& line) {
            line.p.x = p1.x;
            line.p.y = p1.y;
            line.p.z = p1.z;

            line.d.x = p2.x - p1.x;
            line.d.y = p2.y - p1.y;
            line.d.z = p2.z - p1.z;
        }
        
        void renderPSPoints() {
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
            pjPoints.push_back(rp1.projOnPlane());
            pjPoints.push_back(rp2.projOnPlane());

            // Store the symmetric points into a vector
            smPoints.push_back(rp1.symmetric());
            smPoints.push_back(rp2.symmetric());
        }
        
        RelativePosition checkRelativePosition() {
            const double escalarProduct = (ln.d.x)*(pl.n.x) + (ln.d.y)*(pl.n.y) + (ln.d.z)*(pl.n.z);
            
            const Coordinates vectorialProduct {
                (ln.d.y)*(pl.n.z) - (ln.d.z)*(pl.n.y),
                (ln.d.z)*(pl.n.x) - (ln.d.x)*(pl.n.z),
                (ln.d.x)*(pl.n.y) - (ln.d.y)*(pl.n.x)
            };
            
            if(escalarProduct == 0) return PARALLEL;
            else if (vectorialProduct == NULL_VECTOR) return PERPENDICULAR;
            else return OBLIQUE;
        }
        
        RelativePosition relativePosition() {
            return relPos;
        }
        
    private:
    
        Plane& pl;
        Line& ln, pjL, smL;
        RelativePosition relPos;
        std::vector<Coordinates> pjPoints;
        std::vector<Coordinates> smPoints;
        
};