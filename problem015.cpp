#include "lib/mathutils.h"

#include <algorithm>
#include <iostream>

long long latticePaths(int width, int height)
{
    return binomialCoefficient(width + height, std::min(width, height));
}

int main()
{
    std::cout << "Answer: " << latticePaths(20, 20) << '\n';
    return 0;
}
