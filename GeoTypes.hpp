#pragma once

static const unsigned int AXES = 3;

struct Coordinates {
    int x, y, z;
};

struct Point : struct Coordinates {};

struct Line {
    struct Point p;
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