#include <cmath>
#include <cstdlib>
#include <iostream>

int gcd(int a, int b)
{
    while (b != 0) {
        int c = b;
        b = a % b;
        a = c;
    }
    return abs(a);
}

int pythagoreanTripleProduct(int sum)
{
    // Formula for a Pythagorean triple:
    // a = k * (m^2 - n^2), b = k * (2 * m * n), c = k * (m^2 + n^2)
    // where k > 0, 0 < n < m, m - n is odd, and gcd(m, n) = 1
    //
    // a + b + c = k * (2 * m * (m + n))
    // (a + b + c) / 2 = k * (m * (m + n))
    if (sum % 2 != 0) {
        return -1;
    }
    int x = sum / 2;
    int sqrtX = sqrt(x);
    for (int m = 2; m <= sqrtX; ++m) {
        if (x % m != 0) {
            continue;
        }
        int y = x / m; // k * (m + n)
        // m and n must be of different parity.
        for (int n = m % 2 + 1; n < m; n += 2) {
            if (y % (m + n) != 0 || gcd(m, n) != 1) {
                continue;
            }
            int k = y / (m + n);
            int a = k * (m * m - n * n);
            int b = k * 2 * m * n;
            int c = k * (m * m + n * n);
            return a * b * c;
        }
    }
    return -1;
}

int main()
{
    std::cout << "Answer: " << pythagoreanTripleProduct(1000) << '\n';
    return 0;
}
