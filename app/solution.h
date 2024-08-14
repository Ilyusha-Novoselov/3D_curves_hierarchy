#ifndef SOLUTION_H_
#define SOLUTION_H_

#include <vector>
#include <memory>
#include <random>

#include "circle.h"
#include "ellipse.h"
#include "helix.h"

namespace Curves {

enum Type {
    Circle_type,
    Ellipse_type,
    Helix_type
};

class Solution {
public:
    static void generate_curves(std::vector<std::shared_ptr<Curve>>& curves);

    static void perform_task();

private:
    static const int _N;

    static const double PI;

    static const double _min_double, _max_double;
};

}

#endif
