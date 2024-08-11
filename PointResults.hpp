#pragma once

#include <cmath>

#include "GeoTypes.hpp"

template<typename T>
class PointResults {
    
    public:
        PointResults(struct Coordinates& Point, T& geoform) {
            pt = point;
            gf = geoform;
        };
        struct Coordinates* projOnLine() {
            
            tnum = (gf.d.x)*(pt.x - gf.p.x) + (gf.d.y)*(pt.y - gf.p.y) + (gf.d.z)*(pt.z - gf.p.z);

            tden = pow(gf.d.x, 2) + pow(gf.d.y, 2) + pow(gf.d.z, 2);

            t = tnem/tden;

            proj.x = gf.p.x + t*(gf.d.x);
            proj.y = gf.p.y + t*(gf.d.y);
            proj.z = gf.p.z + t*(gf.d.z);
            
            return &proj;
        };
        struct Coordinates* projOnPlan() {
            
            tnum = -(gf.k)*((gf.n.x)*pt.x + (gf.n.y)*pt.y + (gf.n.z)*pt.z);

            tden = pow(gf.n.x, 2) + pow(gf.n.y, 2) + pow(gf.n.z, 2);

            t = tnem/tden;

            proj.x = pt.x + t*(gf.n.x);
            proj.y = pt.y + t*(gf.n.y);
            proj.z = pt.z + t*(gf.n.z);
            
            return &proj;
        };
        struct Coordinates* simetric() {
            
            smt.x = 2*(proj.x) - pt.x;
            smt.y = 2*(proj.y) - pt.y;
            smt.z = 2*(proj.z) - pt.z;
            
            return &smt;
        };
        
    private:
        struct Coordinates pt;
        struct T gf;
        
        struct Coordinates proj;
        struct Coordinates smt;
        
        double t, tnum, tden;
    
};