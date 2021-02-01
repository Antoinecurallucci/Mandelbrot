#include "Convergence.hpp"

Convergence::Convergence(std::string value)
{
    _name = value;
}

//Convergence(std::string value; ColorMap* _colors, int _max_iters) {}

Convergence::~Convergence()
{

}

std::string Convergence::name()
{
    return _name;
}

void Convergence::setColor(ColorMap* colorizer)
{
    colors = colorizer;
}

void Convergence::setIters(const unsigned int value)
{
    max_iters = value;
}

std::string align_right(std::string str, std::string model)
{
    std::string r;
    for(uint32_t i = str.length(); i < model.length(); i += 1 )
        r += " ";
    r += str;
    return r;
}

std::string align_left(std::string str, std::string model)
{
    std::string r;
    r += str;
    for(uint32_t i = str.length(); i < model.length(); i += 1 )
        r += " ";
    return r;
}

std::string Convergence::toString()
{
    std::string resu;
    resu += "Convergence [" + align_left (name(),   "SP_SSE4_OMP_vc") + "] :";
    resu += " Format = "    + align_right(dataFormat, "double") + " |";
    resu += " SIMD = "      + align_right(modeSIMD,         "none") + " |";
    resu += " OpenMP = "    + align_right(modeOPENMP,    "disable") + " |";
    resu += " OTHER = "     + align_right(OTHER,       "unroll 4x") + " |";
    return resu;
}
