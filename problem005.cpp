#include "lib/PrimeSieve.h"

#include <cmath>
#include <iostream>

int lcmOfRange(int upper)
{
    int result = 1;
    int sqrtLimit = sqrt(upper);
    PrimeSieve sieve(upper);
    int primes = sieve.countPrimes();
    for (int i = 1; i <= primes; ++i) {
        int p = sieve.nthPrime(i);
        int x = p;
        if (p <= sqrtLimit) {
            int product = p * p;
            do {
                x = product;
                product *= p;
            } while (product <= upper);
        }
        result *= x; // x = p_i^(floor(log_p_i(upper)))
    }
    return result;
}

int main()
{
    std::cout << "Answer: " << lcmOfRange(20) << '\n';
    return 0;
}
