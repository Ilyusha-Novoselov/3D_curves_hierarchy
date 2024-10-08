#ifndef CIRCLE_H_
#define CIRCLE_H_

#if defined(_WIN32) || defined(_WIN64)
    #include "directive.h"
#else
    #define CURVES_DLL_API
#endif

#include "curve.h"

namespace Curves {

class CURVES_DLL_API Circle : public Curve {
public:
    Circle(double radius);

    Point get_point(double t) override;

    Point first_derivative(double t) override;

    inline double get_radius() { return _radius; }

private:
    double _radius;
};

}

#endif
