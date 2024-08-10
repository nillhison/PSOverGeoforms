#pragma once

#include "GeoTypes.hpp"

class LineResults {
    
    public:
    
        LineResults(struct Line* line, struct Plan* plan) {
            ln = line;
            pl = plan;
        }
        
        struct Line* projOnPlan() {
            
            return &proj;
        }
        
        struct Line* simetric() {
            
            return &smt;
        }
        
    private:
    
        struct Line* ln;
        struct Plan* pl;
        
        struct Line proj;
        struct Line smt;
    
};