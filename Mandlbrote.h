#pragma once

#include <complex>

class Mandlbrote
{
public:
    static const int MAX_ITERATIONS = 1000;
public:
    Mandlbrote();
    virtual ~Mandlbrote();

    static int getIterations(double x, double y);
};


