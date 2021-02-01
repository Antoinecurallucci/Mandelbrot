#include "ColorGreen.hpp"


ColorGreen::ColorGreen(int max_iters) : ColorMap("Green")
{
    setIters(max_iters);
}


void ColorGreen::setIters(int max_iters)
{

    MAX = max_iters;

    for (uint32_t i = 0; i < MAX; ++i)
    {
        const float t = 255.0f * ((float)i/(float)max_iters);
        colors[i] = sf::Color(0, t, 0);
    }
    colors[MAX-1] = sf::Color(0, 0, 0);
}


ColorGreen::~ColorGreen()
{

}
