#ifndef PRIMESIEVE_H
#define PRIMESIEVE_H

#include <vector>

class PrimeSieve
{
public:
    PrimeSieve(int upper);
    int upperBound() const;
    int countPrimes() const;
    int nthPrime(int n) const;
    bool isPrime(int n) const;
private:
    int upper;
    std::vector<bool> sieve;
    std::vector<int> results;
};

#endif
