#pragma once

#include <iostream>

#include "Dialogs"
#include "GeoTypes.hpp"
#include "PointResuslts.hpp"
#include "LineResults.hpp"

void runPOL() {
    
    struct Point* point = new struct Point;
    struct Line* line = new struct Line;
    
    PointResults pointResults(point, line);
    
    point = requestPointData();
    line = requestLineData();
    
    exhibResults(&pointResults);
    
    delete Point;
    delete Line;
    
};

void runPOP() {
    
};

void runLOP() {
    
};