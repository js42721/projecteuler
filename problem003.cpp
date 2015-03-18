#include <cmath>
#include <iostream>

long long largestPrimeFactor(long long n)
{
    long long x = n;
    while (x % 2 == 0) {
        x /= 2;
    }
    if (x == 1) {
        return 2;
    }
    long long factor = 3;
    long long sqrtX = sqrt(x);
    int skip = 1;
    while (factor <= sqrtX) {
        if (x % factor == 0) {
            x /= factor;
            sqrtX = sqrt(x);
        } else if (factor < 7) {
            factor += 2;
        } else {
            // The increment alternates between 4 and 2.
            factor += 2 * (skip + 1);
            skip = (skip + 1) & 1;
        }
    }
    return x;
}

int main()
{
    std::cout << "Answer: " << largestPrimeFactor(600851475143) << '\n';
    return 0;
}
