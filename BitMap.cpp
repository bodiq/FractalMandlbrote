#include "BitMap.h"
#include "BitMapHeader.h"
#include "BitMapInfo.h"


BitMap::BitMap() : m_height(0), m_width(0), m_pPixels(nullptr) {}

BitMap::BitMap(int width, int height) : m_width(width), m_height(height), m_pPixels(new uint8_t[m_height * m_width * 3]{ }) {}

bool BitMap::write(const std::string &filename)
{
    BitMapHead bmh;
    BitMapInfo bmf;

    bmh.filesize = sizeof(BitMapHead) + sizeof(BitMapInfo) + (m_width * m_height * 3);
    bmh.dataoffset = sizeof(BitMapHead) + sizeof(BitMapInfo);

    bmf.height = m_height;
    bmf.width = m_width;

    std::fstream file;
    file.open(filename,  std::ios::out | std::ios::binary);
    if(!file)
    {
        return false;
    }

    file.write(reinterpret_cast<char*>(&bmh), sizeof(bmh));
    file.write(reinterpret_cast<char*>(&bmf), sizeof(bmf));
    file.write(reinterpret_cast<char*>(m_pPixels.get()), m_width * m_height * 3);

    file.close();

    return true;
}

void BitMap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
{
    uint8_t *pPixels = m_pPixels.get();

    pPixels += (y * 3) * m_width + (x * 3);

    pPixels[0] = blue;
    pPixels[1] = green;
    pPixels[2] = red;
}

BitMap::~BitMap() {}