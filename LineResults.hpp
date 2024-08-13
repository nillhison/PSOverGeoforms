#pragma once

#include <cmath>
#include <vector>

#include "GeoTypes.hpp"
#include "PointResults"

class LineResults {
    
    public:
    
        LineResults(Line& line, Plane& plane) {
            ln = line;
            pl = plane;
            
            relPos = checkRelativePosition();
            
            if(relPos != PERPENDICULAR) renderPSPoints();
            
        }
        
        Line& projOnPlane() {
            
            pjL = buildLineGivenTwoPoints(pjPoints[0], pjPoints[1]);
            
            return pjL;
        }
        
        Line& simetric() {
            
            smL = buildLineGivenTwoPoints(smPointss[2], smPoints[3]);
            
            return smL;
        }
        
        Line& buildLineGivenTwoPoints(Coordinates& p1, Coordinates& p2) {
            
        }
        
        void renderPSPoints() {
            
            PointResults<Plane> rp1(ln.p, pl);
                
            // Using t = 1 to render a second point p2 in the Line
            Coordinates p2 = {
                ln.p.x + ln.d.x,
                ln.p.y + ln.d.y,
                ln.p.z + ln.d.z
            };
                
            PointResults<Plane> rp2(p2, pl);
            
            static const std::vector<Coordinates> pjPoints = {
                rp1.projOnPlane(),
                rp2.projOnPlane()
            };
            
            static const std::vector<Coordinates> smPoints = {
                rp1.simetric(),
                rp2.simetric()
            };
            
        }
        
        RelativePosition checkRelativePosition() {
            
            double escalarProduct = (ln.v.x)*(pl.n.x) + (ln.v.y)*(pl.n.y) + (ln.v.z)*(pl.n.z);
            
            Coordinates vectorialProduct {
                (ln.d.y)*(pl.n.z) - (ln.d.z)*(pl.n.y),
                (ln.d.z)*(pl.n.x) - (ln.d.x)*(pl.n.z),
                (ln.d.x)*(pl.n.y) - (ln.d.y)*(pl.n.x)
            };
        
            
            if(escalarProduct == 0) return PARALLEL;
            else if (vectorialProduct = NULL_VECTOR) return PERPENDICULAR;
            else return OBLIQUE;
            
        }
        
        RelativePosition relativePosition() {
            return relPos;
        }
        
    private:
    
        Line ln;
        Plane pl;
        
        Line pjL;
        Line smL;
        
        RelativePosition relPos;
    
};