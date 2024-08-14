#ifndef HELIX_H_
#define HELIX_H_

#include "directive.h"
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
