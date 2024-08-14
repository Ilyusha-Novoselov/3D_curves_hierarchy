#include <omp.h>
#include <algorithm>

#include "solution.h"

namespace Curves {

const double Solution::PI = 3.14159265358979323846;

const int Solution::_N = 50;

const double Solution::_min_double = 0.1;
const double Solution::_max_double = 100.0;

void Solution::generate_curves(std::vector<std::shared_ptr<Curve>> &curves)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> double_dist(_min_double, _max_double);
    std::uniform_int_distribution<int> int_dist(0, 2);

    for (size_t i = 0; i < _N; ++i) {
        Type curve_type = static_cast<Type>(int_dist(gen));

        switch (curve_type) {
        case Circle_type:
            curves.emplace_back(std::make_shared<Circle>(Circle(double_dist(gen))));
            break;

        case Ellipse_type:
            curves.emplace_back(std::make_shared<Ellipse>(Ellipse(double_dist(gen), double_dist(gen))));
            break;

        case Helix_type:
            curves.emplace_back(std::make_shared<Helix>(Helix(double_dist(gen), double_dist(gen))));
            break;

        default:
            break;
        }
    }
}

void Solution::perform_task()
{
    // Task 2 (Populate a container (e.g. vector or list) of objects of these types created in random manner with random parameters):
    std::vector<std::shared_ptr<Curve>> curves_vector {};
    generate_curves(curves_vector);

    // Task 3 (Print coordinates of points and derivatives of all curves in the container at t=PI/4):
    for(size_t i = 0; i < _N; ++i) {
        std::cout << "Curve " << i + 1 << ":" << std::endl;
        std::cout << "Point t = pi/4: " << curves_vector[i]->get_point(PI / 4) << std::endl;
        std::cout << "First derivative t = pi/4: " << curves_vector[i]->first_derivative(PI / 4) << std::endl << std::endl;
    }

    // Task 4 (Populate a second container that would contain only circles from the first container.
    // Make sure the second container shares (i.e. not clones) circles of the first one, e.g. via pointers):
    std::vector<std::shared_ptr<Circle>> circles_vector {};
    for (const auto& elem : curves_vector)
        if (auto circle = std::dynamic_pointer_cast<Circle>(elem))
            circles_vector.emplace_back(std::move(circle));

    // Task 5 (Sort the second container in the ascending order of circles’ radii. That is, the first element has the smallest radius, the last - the greatest):
    std::sort(circles_vector.begin(), circles_vector.end(), [](const std::shared_ptr<Circle>& first, const std::shared_ptr<Circle>& second) {
        return first->get_radius() < second->get_radius();
        });

    // Task 6-7 (Compute the total sum of radii of all curves in the second container):
    // (Implement computation of the total sum of radii using parallel computations)
    double sum = 0.0;
    #pragma omp parallel for reduction(+:sum)
    for(int i = 0; i < circles_vector.size(); ++i)
        sum += circles_vector[i]->get_radius();

    std::cout << "Radiuses sum: " << sum << std::endl;

}

}
