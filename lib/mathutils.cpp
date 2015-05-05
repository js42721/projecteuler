#include "mathutils.h"

#include <algorithm>
#include <cmath>
#include <cstdlib>

bool isPrime(int n)
{
    if (n < 2) {
        return false;
    }
    int a[] = { 2, 3, 5 };
    for (int i = 0; i < 3; ++i) {
        if (n == a[i]) {
            return true;
        }
        if (n % a[i] == 0) {
            return false;
        }
    }
    int inc[] = { 4, 2, 4, 2, 4, 6, 2, 6 };
    int idx = 0;
    int factor = 7;
    int sqrtN = sqrt(n);
    while (factor <= sqrtN) {
        if (n % factor == 0) {
            return false;
        }
        factor += inc[idx];
        idx = (idx + 1) % 8;
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
