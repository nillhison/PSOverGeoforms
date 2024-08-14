#pragma once

#include <cmath>

#include "GeoTypes.hpp"

template<typename T>
class PointResults {
    
    public:
    
        PointResults(Coordinates& point, T& geoform) : pt(point), gf(geoform) {
            pt = point;
            gf = geoform;
        };
        
        Coordinates& projOnLine() {
            tnum = (gf.d.x)*(pt.x - gf.p.x) + (gf.d.y)*(pt.y - gf.p.y) + (gf.d.z)*(pt.z - gf.p.z);
            tden = pow(gf.d.x, 2) + pow(gf.d.y, 2) + pow(gf.d.z, 2);
            t = tnum/tden;

            pjP.x = gf.p.x + t*(gf.d.x);
            pjP.y = gf.p.y + t*(gf.d.y);
            pjP.z = gf.p.z + t*(gf.d.z);
            
            return pjP;
        };
        
        Coordinates& projOnPlane() {
            tnum = -(gf.k)*((gf.n.x)*pt.x + (gf.n.y)*pt.y + (gf.n.z)*pt.z);
            tden = pow(gf.n.x, 2) + pow(gf.n.y, 2) + pow(gf.n.z, 2);
            t = tnum/tden;

            pjP.x = pt.x + t*(gf.n.x);
            pjP.y = pt.y + t*(gf.n.y);
            pjP.z = pt.z + t*(gf.n.z);
            
            return pjP;
        };
        
        Coordinates& symmetric() {
            smP.x = 2*(pjP.x) - pt.x;
            smP.y = 2*(pjP.y) - pt.y;
            smP.z = 2*(pjP.z) - pt.z;
            
            return smP;
        };
        
    private:
        
        T& gf;
        Coordinates& pt, pjP, smP;
        double t, tnum, tden;
    
};