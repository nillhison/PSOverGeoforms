#pragma once

#include "GeoTypes.hpp"

template<typename T>
class PointResults {
    
    public:
        PointResults(struct Point* Point, T* geoform) {
            pt = point;
            gf = geoform;
        };
        struct Point* projOnLine() {
            
            return &proj;
        };
        struct Point* projOnPlan() {
            
            return &proj;
        };
        struct Point* simetric() {
            
            return &smt;
        };
        
    private:
        struct Point* pt;
        struct T* gf;
        
        struct Point proj;
        struct Point smt;
    
};