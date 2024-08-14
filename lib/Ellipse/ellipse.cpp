#include "ellipse.h"

namespace Curves {

Ellipse::Ellipse(double radius_x, double radius_y) {

    if (radius_x <= 0 || radius_y <= 0)
        throw std::invalid_argument("Radius must be positive");

    _radius_x = radius_x;
    _radius_y = radius_y;
}

Point Ellipse::get_point(double t)  {
    return Point(_radius_x * cos(t), _radius_y * sin(t), 0.0);
}

Point Ellipse::first_derivative(double t) {
    return Point(-_radius_x * sin(t), _radius_y * cos(t), 0.0);
}

}
