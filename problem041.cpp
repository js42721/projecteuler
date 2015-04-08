#include "lib/mathutils.h"

#include <algorithm>
#include <iostream>

int largestPandigitalPrime()
{
    int a[] = { 7, 6, 5, 4, 3, 2, 1 };
    int offsets[] = { 0, 3 };
    // Checks 7-digit pandigitals and then 4-digit ones if necessary. All other
    // pandigitals aside from 1 are divisible by 3 since their digit sums are
    // divisible by 3.
    for (int i = 0; i < 2; ++i) {
        int start = offsets[i];
        do {
            int val = 0;
            for (int j = start; j < 7; ++j) {
                val = 10 * val + a[j];
            }
            if (isPrime(val)) {
                return val;
            }
        } while (std::prev_permutation(a + start, a + 7));
    }
}

int main()
{
    std::cout << "Answer: " << largestPandigitalPrime() << '\n';
    return 0;
}
