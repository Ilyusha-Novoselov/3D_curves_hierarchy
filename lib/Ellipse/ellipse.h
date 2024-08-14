#ifndef ELLIPSE_H_
#define ELLIPSE_H_

#include "directive.h"
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
