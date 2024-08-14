#include "circle.h"

namespace Curves {

Circle::Circle(double radius) {

    if (radius <= 0)
        throw std::invalid_argument("Radius must be positive");

    _radius = radius;
}

Point Circle::get_point(double t)  {
    return Point(_radius * cos(t), _radius * sin(t), 0.0);
}

Point Circle::first_derivative(double t) {
    return Point(-_radius * sin(t), _radius * cos(t), 0.0);
}

}
