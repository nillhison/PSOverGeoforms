#pragma once

#include <tuple>
#include <string_view>

struct Coordinates
{
    // Might be coordinates for a point or a vector
    double x, y, z;
    bool operator==(const Coordinates& cd) const
    {
        return std::tie(x, y, z) == std::tie(cd.x, cd.y, cd.z);
    }
    
};

struct Line
{
    /** Parametic equations:
     * 
     *  x = p.x + t * d.x
     *  y = p.y + t * d.y
     *  z = p.z + t * d.z
     * 
     * Where t is a parameter **/
    Coordinates p; // Point on the line
    Coordinates d; // Direction vector of the line
};

struct Plane
{
    /** Plane equation:
     * 
     *  x * n.x + y * n.y + z * n.z + k = 0
     * 
     * Where k is the plane's constant **/
    double k; // Plane's constant
    Coordinates n; // Normal vector of the plane
};

constexpr std::string_view locus[] {
    {"point"},                        // locus[0]
    {"point on the line"},            // locus[1]
    {"direction vector of the line"}, // locus[2]
    {"normal vector of the plane"}    // locus[3]
};

enum Operation
{
    INITIAL,
    POINT_OVER_LINE,
    POINT_OVER_PLANE,
    LINE_OVER_PLANE,
    EXIT_APP
};

enum RelativePosition
{
    /** Relative positions between the plane and the line.
     *  Used to filter the algorithm used to calculate
     *  the line projection and its symmetric **/
    PARALLEL,
    PERPENDICULAR,
    OBLIQUE
};

const unsigned int AXES = 3;
const Coordinates NULL_VECTOR = {0, 0, 0};