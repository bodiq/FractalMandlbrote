#pragma once

#include <string>
#include <cstdint>
#include <iostream>
#include <fstream>

class BitMap
{
public:
    BitMap();
    BitMap(int, int);
    bool write(const std::string &filename);
    void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
    virtual ~BitMap();
private:
    int m_width;
    int m_height;
    std::unique_ptr<uint8_t> m_pPixels;
};


