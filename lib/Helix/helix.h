#ifndef HELIX_H_
#define HELIX_H_

#if defined(_WIN32) || defined(_WIN64)
    #include "directive.h"
#else
    #define CURVES_DLL_API
#endif

#include "curve.h"

namespace Curves {

class CURVES_DLL_API Helix : public Curve {
public:
    Helix(double radius, double step);

    Point get_point(double t) override;

    Point first_derivative(double t) override;

private:
    double _radius, _step;
};

}

#endif
