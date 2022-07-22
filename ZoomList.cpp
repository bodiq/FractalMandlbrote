#include "ZoomList.h"

ZoomList::ZoomList() : m_width(0), m_height(0), m_scale(1.0), m_xCenter(0.0), m_yCenter(0.0) {}

ZoomList::ZoomList(int width, int height) : m_width(width), m_height(height) {}

void ZoomList::add(const Zoom &zoom)
{
    zooms.push_back(zoom);

    m_xCenter += (zoom.m_x - m_width / 2) * m_scale;
    m_yCenter += (zoom.m_y - m_height / 2) * m_scale;

    m_scale *= zoom.m_scale;

    std::cout << m_xCenter << ", " << m_yCenter << ", " << m_scale << std::endl;
}

std::pair<double, double> ZoomList::doZoom(int x, int y)
{
    double xFractal = (x - m_width / 2) * m_scale + m_xCenter;
    double yFractal = (y - m_height / 2) * m_scale + m_yCenter;

    return std::pair<double, double>(xFractal, yFractal);
}