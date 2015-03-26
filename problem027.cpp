#include "lib/PrimeSieve.h"

#include <cmath>
#include <iostream>
#include <utility>

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

std::pair<int, int> eulerNumbers()
{
    int bestA, bestB, bestN = 0;
    PrimeSieve sieve(999);
    int primes = sieve.countPrimes();
    // b must be prime or n^2 + a * n + b will not produce a prime when n = 0.
    // b = 2 is skipped since it can only result in 2 primes (when a = -1).
    for (int i = 2; i <= primes; ++i) {
        int b = sieve.nthPrime(i);
        // Skipping the only even value of b allows even values of a to be
        // skipped since a must be odd for the equation to work when b is odd
        // and n = 1.
        for (int a = -999; a <= 999; a += 2) {
            int n = 0;
            for (;;) {
                int c = n * (a + n) + b;
                if (c < 2) {
                    break;
                }
                if (!((c <= 999) ? sieve.isPrime(c) : isPrime(c))) {
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
