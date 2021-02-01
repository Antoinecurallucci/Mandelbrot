#include "ColorAntoine.hpp"


ColorAntoine::ColorAntoine(int max_iters) : ColorMap("Antoine")
{
    setIters(max_iters);
}


void ColorAntoine::setIters(int max_iters)
{

    MAX = max_iters;

    for (uint32_t i = 0; i < MAX; ++i)
    {
        const float t = 255.0f * ((float)i/(float)max_iters);
        colors[i] = sf::Color(0, 0, t);
    }
    colors[MAX-1] = sf::Color(0, 0, 0);
}


ColorAntoine::~ColorAntoine()
{

}
