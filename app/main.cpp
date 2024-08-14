#include "solution.h"

int main()
{
    try {
        Curves::Solution::perform_task();
    }
    catch(std::invalid_argument& e) {
        std::cout << e.what();
    }

    return 0;
}
