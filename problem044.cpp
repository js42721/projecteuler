#include <cmath>
#include <iostream>
#include <limits>

bool isPentagonal(long long n)
{
    return fmod(sqrt(24 * n + 1), 6) == 5;
}

long long minimalDifference()
{
    long long minD = std::numeric_limits<long long>::max();
    long long current = 5;
    long long inc = 7;
    // The outer loop generates pentagonal numbers until the distance to the
    // next number exceeds the recorded minimal difference. After that point,
    // all differences will be greater than the recorded minimal difference,
    // meaning it is the true minimal difference.
    while (inc < minD) {
        long long p = current - (inc - 3);
        long long dec = inc - 6;
        do {
            long long d = current - p;
            if (d >= minD) {
                break;
            }
            if (isPentagonal(d) && isPentagonal(current + p)) {
                minD = d;
                break;
            }
            p -= dec;
            dec -= 3;
        } while (p >= 1);
        current += inc;
        inc += 3;
    }
    return minD;
}

int main()
{
    std::cout << "Answer: " << minimalDifference() << '\n';
    return 0;
}
