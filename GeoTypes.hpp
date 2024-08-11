#pragma once

static const unsigned int AXES = 3;

struct Coordinates {
    int x, y, z;
};

struct Line {
    struct Coordinates p;
    struct Coordinates d;
};

struct Plan {
    int k;
    struct Coordinates n;
};

enum Operation {
    Initial,
    PointOverLine,
    PoinOverPlan,
    LineOverPlan
    NotAllowed,
    Exit
};

enum ResultType {
    PointData,
    LineData
};