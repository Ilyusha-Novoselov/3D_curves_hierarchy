#ifndef ELLIPSE_H_
#define ELLIPSE_H_

#if defined(_WIN32) || defined(_WIN64)
    #include "directive.h"
#else
    #define CURVES_DLL_API
#endif

#include "curve.h"

namespace Curves {

class CURVES_DLL_API Ellipse : public Curve {
public:
    Ellipse(double radius_x, double radius_y);

    Point get_point(double t) override;

    Point first_derivative(double t) override;

private:
    double _radius_x, _radius_y;
};

}

#endif
