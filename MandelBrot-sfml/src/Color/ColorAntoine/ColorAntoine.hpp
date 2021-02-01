#ifndef _ColorAntoine_
#define _ColorAntoine_

#include "../ColorMap.hpp"

class ColorAntoine : public ColorMap {
public:

    ColorAntoine(int max_iters = 255);

    virtual void setIters(int max_iters);

    virtual ~ColorAntoine();
};

#endif // _ColorAntoine_
