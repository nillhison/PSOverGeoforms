#pragma once

#include "GeoTypes.hpp"
#include "PointResults.hpp"
#include "LineResults.hpp"
#include "Dialogs.hpp"

void runPointOverLine() {
    
    Coordinates* point = new Coordinates;
    Line* line = new Line;
    
    reqPointData(*point);
    reqLineData(*line);
    
    PointResults<Line> pointResults(*point, *line);
    
    exhibitResults<Coordinates>(pointResults.projOnLine(), pointResults.symmetric());
    
    delete point;
    delete line;
    
}

void runPointOverPlane() {
    
    Coordinates* point = new Coordinates;
    Plane* plane = new Plane;
    
    reqPointData(*point);
    reqPlaneData(*plane);
    
    PointResults<Plane> pointResults(*point, *plane);
    
    exhibitResults<Coordinates>(pointResults.projOnPlane(), pointResults.symmetric());
    
    delete point;
    delete plane;
    
}

void runLineOverPlane() {
    
    Line* line = new Line;
    Plane* plane = new Plane;
    
    reqLineData(*line);
    reqPlaneData(*plane);
    
    LineResults lineResults(*line, *plane);
    
    logAboutRelativePosition(lineResults.relativePosition());
    
    if(lineResults.relativePosition() != PERPENDICULAR) {
        exhibitResults<Line>(lineResults.projOnPlane(), lineResults.symmetric());
    }
    
    delete line;
    delete plane;
    
}