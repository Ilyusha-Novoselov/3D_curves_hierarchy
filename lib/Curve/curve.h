#ifndef CURVE_H_
#define CURVE_H_

#include <cmath>

#include "directive.h"
#include "point.h"

namespace Curves {

class CURVES_DLL_API Curve {
public:
    Curve() = default;

    virtual ~Curve() = default;

    virtual Point get_point(double t) = 0;

    virtual Point first_derivative(double t) = 0;
};

}

#endif
