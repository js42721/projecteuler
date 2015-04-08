#include "mathutils.h"

#include <algorithm>
#include <cmath>
#include <cstdlib>

bool isPrime(int n)
{
    if (n < 2) {
        return false;
    }
    if (n == 2 || n == 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    int factor = 5;
    int sqrtN = sqrt(n);
    int twoFour = 2;
    while (factor <= sqrtN) {
        if (n % factor == 0) {
            return false;
        }
        factor += twoFour;
        twoFour ^= 6;
    }
    return true;
}

int gcd(int a, int b)
{
    while (b != 0) {
        int c = b;
        b = a % b;
        a = c;
    }
    return abs(a);
}

int lcm(int a, int b)
{
    return abs(a / gcd(a, b) * b);
}

long long binomialCoefficient(int n, int k)
{
    if (k < 0 || k > n) {
        return 0;
    }
    k = std::min(k, n - k);
    long long result = 1;
    for (int i = 0; i < k; ++i) {
        result = result * (n - i) / (i + 1);
    }
    return result;
}
