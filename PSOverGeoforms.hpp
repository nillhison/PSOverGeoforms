#pragma once

#include "GeoTypes.hpp"
#include "PointResults.hpp"
#include "LineResults.hpp"
#include "Dialogs.hpp"

void runPOL() {
    
    struct Coordinates* point = new Point;
    struct Line* line = new Line;
    
    reqPointData(*point);
    reqLineData(*line);
    
    PointResults pointResults(*point, *line);
    
    exhibitResults(pointResults.projOnLine(), pointResults.simetric(), PointData);
    
    delete Point;
    delete Line;
    
}

void runPOP() {
    
    struct Coordinates* point = new Point;
    struct Plan* plan = new Plan;
    
    reqPointData(*point);
    reqPlanData(*plan);
    
    PointResults pointResults(*point, *plan);
    
    exhibitResults(pointResults.projOnPlan(), pointResults.simetric(), PointData);
    
    delete Point;
    delete Plan;
    
}

void runLOP() {
    
    struct Line* line = new Line;
    struct Plan* plan = new Plan;
    
    reqLineData(*line);
    reqPlanData(*plan);
    
    PointResults lineResults(*line, *plan);
    
    exhibitResults(lineResults.projOnPlan(), lineResults.simetric(), LineData);
    
    delete Line;
    delete Plan;
    
}