#pragma once

#include <cmath>
#include <vector>

#include "GeoTypes.hpp"
#include "PointResults.hpp"

class LineResults
{
    
    public:
    
        LineResults(Line& line, Plane& plane) : m_line(line), m_plane(plane)
        {
            m_line = line;
            m_plane = plane;
            relPos = CheckRelativePosition();
            
            if(relPos != PERPENDICULAR) RenderPSPoints();
        }
        
        Line& ProjOnPlane()
        {
            BuildLineGivenTwoPoints(pjPoints[0], pjPoints[1], m_projection);
            return m_projection;
        }

        Line& Symmetric()
        {
            BuildLineGivenTwoPoints(smPoints[0], smPoints[1], m_symmetric);
            return m_symmetric;
        }

        void BuildLineGivenTwoPoints(Coordinates& p1, Coordinates& p2, Line& line)
        {
            line.p.x = p1.x;
            line.p.y = p1.y;
            line.p.z = p1.z;
            line.d.x = p2.x - p1.x;
            line.d.y = p2.y - p1.y;
            line.d.z = p2.z - p1.z;
        }
        
        void RenderPSPoints()
        {
            // Select two points on the line and project them as well as get its symmetric
            
            // First point: using t = 0 (this is the given point on the line itself)
            PointResults<Plane> p1Results(m_line.p, m_plane);
                
            // Second point: using t = 1 to render a second point p2 on the Line
            Coordinates p2 = {
                m_line.p.x + m_line.d.x,
                m_line.p.y + m_line.d.y,
                m_line.p.z + m_line.d.z
            };
                
            PointResults<Plane> p2Results(p2, m_plane);
            
            // Store the points projections on the plan into a vector
            pjPoints.push_back(p1Results.ProjOnPlane());
            pjPoints.push_back(p2Results.ProjOnPlane());

            // Store the symmetric points into a vector
            smPoints.push_back(p1Results.Symmetric());
            smPoints.push_back(p2Results.Symmetric());
        }
        
        RelativePosition CheckRelativePosition()
        {
            const double dotProduct = (m_line.d.x)*(m_plane.n.x) + (m_line.d.y)*(m_plane.n.y) + (m_line.d.z)*(m_plane.n.z);
            const Coordinates vectorialProduct {
                (m_line.d.y)*(m_plane.n.z) - (m_line.d.z)*(m_plane.n.y),
                (m_line.d.z)*(m_plane.n.x) - (m_line.d.x)*(m_plane.n.z),
                (m_line.d.x)*(m_plane.n.y) - (m_line.d.y)*(m_plane.n.x)
            };
            
            if(dotProduct == 0) return PARALLEL;
            else if (vectorialProduct == NULL_VECTOR) return PERPENDICULAR;
            else return OBLIQUE;
        }
        
        RelativePosition RelPos()
        {
            return relPos;
        }
        
    private:
    
        Plane& m_plane;
        Line& m_line, m_projection, m_symmetric;
        RelativePosition relPos;
        std::vector<Coordinates> pjPoints;
        std::vector<Coordinates> smPoints;
};