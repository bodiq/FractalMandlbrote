#pragma once

#include <iostream>

#pragma pack(2)

struct BitMapHead
{
    char header[2] = {'B', 'M'};
    int32_t filesize;
    int32_t reserved = {0};
    int32_t dataoffset;
};