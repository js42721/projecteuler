#include "lib/PrimeSieve.h"

#include <cmath>
#include <iostream>

int main()
{
    int n = 10001;
    // The upper bound is for n >= 6 and is from the paper "The kth prime is
    // greater than k(ln k + ln ln k - 1) for k >= 2" by Pierre Dusart.
    int upper = n * (log(n) + log(log(n)));
    PrimeSieve sieve(upper);
    std::cout << "Answer: " << sieve.nthPrime(n) << '\n';
    return 0;
}
