#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include <thread>
#include <string>

#include "../Color/ColorMap.hpp"
#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include <thread>
#include <immintrin.h>
#include <unistd.h>

#ifndef CONVERGENCE_H_
#define CONVERGENCE_H_

class Convergence {

protected:
    ColorMap* colors;
    int max_iters;
    std::string _name;

    std::string dataFormat;
    std::string modeSIMD;
    std::string modeOPENMP;
    std::string OTHER;

public:

    Convergence(std::string value);

    virtual ~Convergence();

    virtual void updateImage(const long double d_zoom, const long double d_offsetX, const long double d_offsetY, const int IMAGE_WIDTH, const int IMAGE_HEIGHT, float* ptr) = 0;

    std::string name();

    void setColor(ColorMap* colorizer);

    void setIters(const unsigned int value);

    std::string toString();

    virtual bool is_valid() = 0;
};

#endif
