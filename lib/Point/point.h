#ifndef POINT_H_
#define POINT_H_

#include <iostream>

#include "directive.h"

namespace Curves {

class CURVES_DLL_API Point {
public:
    Point(double x, double y, double z) : _x(x), _y(y), _z(z) {}

    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point._x << ", " << point._y << ", " << point._z << ")";
        return os;
    }

private:
    double _x, _y, _z;
};

}

#endif
