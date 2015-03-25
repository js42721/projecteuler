#include "lib/PrimeSieve.h"

#include <iostream>

int main()
{
    long long ans = 0;
    PrimeSieve sieve(1999999);
    int primes = sieve.countPrimes();
    for (int i = 1; i <= primes; ++i) {
        ans += sieve.nthPrime(i);
    }
    std::cout << "Answer: " << ans << '\n';
    return 0;
}
