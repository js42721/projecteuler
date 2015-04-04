#include "lib/mathutils.h"

#include <iostream>
#include <vector>

bool isTruncatablePrime(int n)
{
    if (n <= 10 || !isPrime(n)) {
        return false;
    }
    int x = 10;
    while (x < n) {
        if (!isPrime(n % x) || !isPrime(n / x)) {
            return false;
        }
        x *= 10;
    }
    return true;
}

std::vector<int> truncatablePrimes()
{
    // Possible truncatable primes will have the following:
    // 1) 2, 3, 5, or 7 as the most significant digit.
    // 2) 1, 3, 7, or 9 for each of the middle digits.
    // 3) 3 or 7 as the least significant digit.
    int d1[] = { 2, 3, 5, 7 };
    int d2[] = { 1, 3, 7, 9 };
    int d3[] = { 3, 7 };
    std::vector<int> results;
    int product = 8;
    for (int digits = 2;; ++digits) {
        for (int i = 0; i < product; ++i) {
            int j = i;
            int val = d1[j % 4];
            j /= 4;
            for (int k = 2; k < digits; ++k) {
                val = 10 * val + d2[j % 4];
                j /= 4;
            }
            val = 10 * val + d3[j % 2];
            j /= 2;
            if (isTruncatablePrime(val)) {
                results.push_back(val);
                if (results.size() == 11) {
                    return results;
                }
            }
        }
        product *= 4;
    }
}

int main()
{
    int ans = 0;
    std::vector<int> results = truncatablePrimes();
    for (int i = 0; i < results.size(); ++i) {
        ans += results[i];
    }
    std::cout << "Answer: " << ans << '\n';
    return 0;
}
