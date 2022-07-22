#pragma once


struct Zoom
{
    int m_x;
    int m_y;
    double m_scale;

    Zoom() : m_x(0), m_y(0), m_scale(0.0) {}
    Zoom(int x, int y, double scale) : m_x(x), m_y(y),m_scale(scale) {}

};