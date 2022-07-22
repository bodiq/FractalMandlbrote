#pragma once

#include "Zoom.h"
#include <vector>
#include <iostream>

class ZoomList
{
public:
    ZoomList();
    ZoomList(int width, int height);
    void add(const Zoom &zoom);
    std::pair<double, double> doZoom(int x, int y);

private:
    int m_width;
    int m_height;

    double m_scale = 1.0;
    double m_xCenter;
    double m_yCenter;

    std::vector<Zoom> zooms;
};


