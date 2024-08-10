#pragma once

struct Point {
    int x, y, z;
};

struct Line {
    struct Point pt;
    int dx, dy, dz;
};

struct Plan {
    int k;
    int nx, ny, nz;
};

enum Operation {
    Initial,
    PointOverLine,
    PoinOverPlan,
    LineOverPlan
    NotAllowed,
    Exit
};