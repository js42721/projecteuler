#include "PrimeSieve.h"

#include <cmath>
#include <stdexcept>

PrimeSieve::PrimeSieve(int upper)
: upper(upper), sieve(upper / 3 + 1, true)
{
    if (upper < 0) {
        throw std::invalid_argument("Negative upper bound");
    }
    sieve[0] = false;
    if (upper < 2) {
        return;
    }
    int s1 = 7, s2 = 3;
    int twoSix = 2;
    int sqrtLimit = sqrt(upper) / 3;
    for (int i = 1; i <= sqrtLimit; ++i) {
        if (sieve[i]) {
            int s3 = s1 + s2;
            for (int j = s1 + i; j < sieve.size(); j += s3) {
                sieve[j] = false;
            }
            for (int j = s3 + i; j < sieve.size(); j += s3) {
                sieve[j] = false;
            }
        }
        s2 += 2;
        s1 += twoSix;
        twoSix ^= 4;
    }
    results.push_back(2);
    results.push_back(3);
    for (int i = 1; i < sieve.size(); ++i) {
        if (sieve[i]) {
            results.push_back(3 * i + i % 2 + 1);
        }
    }
    if (results[results.size() - 1] > upper) {
        results.pop_back();
    }
}

int PrimeSieve::upperBound() const
{
    return upper;
}

int PrimeSieve::countPrimes() const
{
    return results.size();
}

int PrimeSieve::nthPrime(int n) const
{
    if (n < 1 || n > results.size()) {
        throw std::out_of_range("n out of range");
    }
    return results[n - 1];
}

bool PrimeSieve::isPrime(int n) const
{
    if (n < 0 || n > upper) {
        throw std::out_of_range("n out of range");
    }
    if (n == 2 || n == 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    return sieve[n / 3];
}
