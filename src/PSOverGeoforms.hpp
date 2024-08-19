#pragma once

#include "GeoTypes.hpp"
#include "PointResults.hpp"
#include "LineResults.hpp"
#include "Dialogs.hpp"

void RunPointOverLine()
{
    Coordinates* point = new Coordinates;
    Line* line = new Line;
    
    ReqPointData(*point);
    ReqLineData(*line);
    
    PointResults<Line> pointResults{*point, *line};
    WritePointResults(pointResults.ProjOnLine(), pointResults.Symmetric());
    
    delete point;
    delete line;
}

void RunPointOverPlane()
{
    Coordinates* point = new Coordinates;
    Plane* plane = new Plane;
    
    ReqPointData(*point);
    ReqPlaneData(*plane);
    
    PointResults<Plane> pointResults{*point, *plane};
    WritePointResults(pointResults.ProjOnPlane(), pointResults.Symmetric());
    
    delete point;
    delete plane;
}

void RunLineOverPlane()
{
    Line* line = new Line;
    Plane* plane = new Plane;
    
    ReqLineData(*line);
    ReqPlaneData(*plane);
    
    LineResults lineResults{*line, *plane};
    LogAboutRelativePosition(lineResults.RelPos());
    if(lineResults.RelPos() != PERPENDICULAR)
    {
        WriteLineResults(lineResults.ProjOnPlane(), lineResults.Symmetric());
    }
    
    delete line;
    delete plane;
}