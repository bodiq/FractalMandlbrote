#include "BitMap.h"
#include "Mandlbrote.h"
#include "ZoomList.h"

static const int WIDTH = 800;
static const int HEIGHT = 600;

int main()
{

    std::unique_ptr<int[]> histogram (new int[Mandlbrote::MAX_ITERATIONS + 1]);
    std::unique_ptr<int[]> fractal (new int[HEIGHT * WIDTH]);

    BitMap bitmap(WIDTH, HEIGHT);

    double min =  99999;
    double max = -99999;

    ZoomList zoomList(WIDTH, HEIGHT);

    zoomList.add(Zoom(WIDTH / 2, HEIGHT / 2, 4.0 / WIDTH));
    zoomList.add(Zoom(295, HEIGHT - 202, 0.1));
    zoomList.add(Zoom(312, HEIGHT - 304, 0.1));

    for(int y = 0; y < HEIGHT; y++)
    {
        for(int x = 0; x < WIDTH; x++)
        {
            std::pair<double, double> xyFractals = zoomList.doZoom(x, y);

            int iterations = Mandlbrote::getIterations(xyFractals.first, xyFractals.second);

            fractal[y * WIDTH + x] = iterations;

            if(iterations != Mandlbrote::MAX_ITERATIONS)
            {
                histogram[iterations]++;
            }
        }
    }

    int total = 0;
    for(int i = 0; i < Mandlbrote::MAX_ITERATIONS; i++)
    {
        total += histogram[i];
    }

    for(int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {

            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            int iterations = fractal[y * WIDTH + x];

            if(iterations != Mandlbrote::MAX_ITERATIONS)
            {
                double hue = 0.0;

                for (int i = 0; i < iterations; i++) {
                    hue += static_cast<double>(histogram[i]) / total;
                }
                green = pow(255, hue);
            }
            bitmap.setPixel(x, y, red, green, blue);
        }
    }

    bitmap.write("test1.bmp");

    std::cout << "Finished" << std::endl;
    return 0;
}
