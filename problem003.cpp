#include <cmath>
#include <iostream>

long long largestPrimeFactor(long long n)
{
    if (n < 2) {
        return -1;
    }
    int a[] = { 2, 3, 5 };
    long long x = n;
    for (int i = 0; i < 3; ++i) {
        int factor = a[i];
        while (x % factor == 0) {
            x /= factor;
        }
        if (x == 1) {
            return factor;
        }
    }
    int inc[] = { 4, 2, 4, 2, 4, 6, 2, 6 };
    int idx = 0;
    long long factor = 7;
    long long sqrtX = sqrt(x);
    while (factor <= sqrtX) {
        if (x % factor == 0) {
            x /= factor;
            sqrtX = sqrt(x);
        } else {
            factor += inc[idx];
            idx = (idx + 1) % 8;
        }
    }
    return x;
}

int main()
{
    std::cout << "Answer: " << largestPrimeFactor(600851475143) << '\n';
    return 0;
}
