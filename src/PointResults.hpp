#pragma once

#include <cmath>

#include "GeoTypes.hpp"

template<typename T>
class PointResults
{
    
    public:
    
        PointResults(Coordinates& point, T& geoform) : m_point(point), m_geoform(geoform)
        {
            m_point = point;
            m_geoform = geoform;
        };
        
        Coordinates& ProjOnLine()
        {
            tnum = (m_geoform.d.x)*(m_point.x - m_geoform.p.x) + (m_geoform.d.y)*(m_point.y - m_geoform.p.y) + (m_geoform.d.z)*(m_point.z - m_geoform.p.z);
            tden = pow(m_geoform.d.x, 2) + pow(m_geoform.d.y, 2) + pow(m_geoform.d.z, 2);
            t = tnum/tden;

            m_projection.x = m_geoform.p.x + t*(m_geoform.d.x);
            m_projection.y = m_geoform.p.y + t*(m_geoform.d.y);
            m_projection.z = m_geoform.p.z + t*(m_geoform.d.z);
            
            return m_projection;
        };
        
        Coordinates& ProjOnPlane()
        {
            tnum = -(m_geoform.k) - ((m_geoform.n.x)*m_point.x + (m_geoform.n.y)*m_point.y + (m_geoform.n.z)*m_point.z);
            tden = pow(m_geoform.n.x, 2) + pow(m_geoform.n.y, 2) + pow(m_geoform.n.z, 2);
            t = tnum/tden;

            m_projection.x = m_point.x + t*(m_geoform.n.x);
            m_projection.y = m_point.y + t*(m_geoform.n.y);
            m_projection.z = m_point.z + t*(m_geoform.n.z);
            
            return m_projection;
        };
        
        Coordinates& Symmetric()
        {
            m_symmetric.x = 2*(m_projection.x) - m_point.x;
            m_symmetric.y = 2*(m_projection.y) - m_point.y;
            m_symmetric.z = 2*(m_projection.z) - m_point.z;
            
            return m_symmetric;
        };
        
    private:
        
        T& m_geoform;
        Coordinates& m_point, m_projection, m_symmetric;
        double t, tnum, tden;
};