#ifndef _ColorGreen_
#define _ColorGreen_

#include "../ColorMap.hpp"

class ColorGreen : public ColorMap {
public:

    ColorGreen(int max_iters = 255);

    virtual void setIters(int max_iters);

    virtual ~ColorGreen();
};

#endif // _ColorGreen_
