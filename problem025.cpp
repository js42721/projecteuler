#include <cmath>
#include <iostream>

const double phi = (1 + sqrt(5)) / 2;

int fibIndex(int digits)
{
    return ((digits - 1) * log(10) + log(5) / 2) / log(phi) + 1;
}

int main()
{
    std::cout << "Answer: " << fibIndex(1000) << '\n';
    return 0;
}
