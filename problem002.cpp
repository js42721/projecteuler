#include <cmath>
#include <iostream>

const double phi = (1 + sqrt(5)) / 2;

int fibIndex(int n)
{
    return log(n * sqrt(5) + 0.5) / log(phi);
}

int fib(int n)
{
    // Accurate only up to the 70th term due to the precision of double.
    return (pow(phi, n) - pow(-phi, -n)) / sqrt(5) + 0.5;
}

int sumOfEvenFib(int upper)
{
    // I.e., the sum of every 3rd Fibonacci term up to the given limit.
    return (fib(3 * (fibIndex(upper) / 3) + 2) - 1) / 2;
}

int main()
{
    std::cout << "Answer: " << sumOfEvenFib(4000000) << '\n';
    return 0;
}
