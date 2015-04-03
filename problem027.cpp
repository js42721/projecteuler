#include "lib/mathutils.h"
#include "lib/primesieve.h"

#include <iostream>
#include <utility>

std::pair<int, int> eulerNumbers()
{
    int bestA, bestB, bestN = 0;
    PrimeSieve sieve(999);
    int primes = sieve.countPrimes();
    // b must be prime or n^2 + an + b will not produce a prime when n = 0.
    // b = 2 is skipped since it stops producing primes when n reaches 2 or
    // earlier.
    for (int i = 2; i <= primes; ++i) {
        int b = sieve.nthPrime(i);
        // Skipping the only even value of b allows even values of a to be
        // skipped since a must be odd for the equation to work when b is odd
        // and n = 1.
        for (int a = -999; a <= 999; a += 2) {
            int n = 0;
            for (;;) {
                int c = n * (a + n) + b;
                if (c < 2 || !((c <= 999) ? sieve.isPrime(c) : isPrime(c))) {
                    break;
                }
                ++n;
            }
            if (n > bestN) {
                bestA = a;
                bestB = b;
                bestN = n;
            }
        }
    }
    return std::make_pair(bestA, bestB);
}

int main()
{
    std::pair<int, int> ans = eulerNumbers();
    std::cout << "Answer: " << ans.first * ans.second << '\n';
    return 0;
}
