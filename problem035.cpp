#include "lib/mathutils.h"

#include <iostream>
#include <vector>

bool isCircularPrime(int n)
{
    if (!isPrime(n)) {
        return false;
    }
    int x = n;
    int mult = 1;
    int digits = 1;
    while (x /= 10) {
        mult *= 10;
        ++digits;
    }
    x = n;
    for (int i = 1; i < digits; ++i) {
        x = mult * (x % 10) + x / 10;
        if (!isPrime(x)) {
            return false;
        }
    }
    return true;
}

std::vector<int> circularPrimes(int maxDigits)
{
    // If a number that is not 2 or 5 contains as much as a single even digit
    // or 5, it cannot be a circular prime since one of its rotations will be
    // composite. The following code skips numbers with bad digits by iterating
    // over the Cartesian product of the good digits with themselves.
    int d[] = { 1, 3, 7, 9 };
    std::vector<int> results;
    results.push_back(2);
    results.push_back(5);
    for (int repeats = 1; repeats <= maxDigits; ++repeats) {
        int i = 0;
        for (;;) {
            int j = i;
            int val = 0;
            for (int k = 0; k < repeats; ++k) {
                val = 10 * val + d[j % 4];
                j /= 4;
            }
            if (j != 0) {
                break;
            }
            if (isCircularPrime(val)) {
                results.push_back(val);
            }
            ++i;
        }
    }
    return results;
}

int main()
{
    // The exclusive upper limit is one million so 6 digits will do.
    std::cout << "Answer: " << circularPrimes(6).size() << '\n';
    return 0;
}
