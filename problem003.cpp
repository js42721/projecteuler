#include <cmath>
#include <iostream>

long long largestPrimeFactor(long long n)
{
    if (n < 2) {
        return -1;
    }
    static int a[] = { 2, 3 };
    long long x = n;
    for (int i = 0; i < 2; ++i) {
        int factor = a[i];
        while (x % factor == 0) {
            x /= factor;
        }
        if (x == 1) {
            return factor;
        }
    }
    long long factor = 5;
    long long sqrtX = sqrt(x);
    int twoFour = 2;
    while (factor <= sqrtX) {
        if (x % factor == 0) {
            x /= factor;
            sqrtX = sqrt(x);
        } else {
            factor += twoFour;
            twoFour ^= 6;
        }
    }
    return x;
}

int main()
{
    std::cout << "Answer: " << largestPrimeFactor(600851475143) << '\n';
    return 0;
}
