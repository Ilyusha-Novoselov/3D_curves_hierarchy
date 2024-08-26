#include "helix.h"

namespace Curves {

Helix::Helix(double radius, double step)
{
    if (radius <= 0)
        throw std::invalid_argument("Radius must be positive");

    _radius = radius;
    _step = step;
}

Point Helix::get_point(double t)  {
    double two_pi = 2 * 3.14159265358979323846;
    return Point(_radius * cos(t), _radius * sin(t), _step * t / two_pi);
}

Point Helix::first_derivative(double t) {
    return Point(-_radius * sin(t), _radius * cos(t), _step);
}

}
