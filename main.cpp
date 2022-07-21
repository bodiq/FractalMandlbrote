#include "BitMap.h"

#define WIDTH 800
#define HEIGHT 600

int main()
{
    BitMap bitmap(WIDTH, HEIGHT);


    for(size_t x = 0; x < WIDTH; x++)
    {
        for(size_t y = 0; y < HEIGHT; y++)
        {
            bitmap.setPixel(x, y, 255, 0, 0);
        }
    }

    bitmap.write("test.bmp");

    std::cout << "Finished" << std::endl;
    return 0;
}
