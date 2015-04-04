#include "lib/mathutils.h"

#include <cmath>
#include <iostream>

int rightestTrianglePerimeter(int upper)
{
    int result = -1;
    int maxTriples = 0;
    // Counts Pythagorean triples.
    for (int p = 12; p <= upper; p += 2) {
        int triples = 0;
        int x = p / 2;
        int sqrtX = sqrt(x);
        for (int m = 2; m <= sqrtX; ++m) {
            if (x % m != 0) {
                continue;
            }
            int y = x / m;
            for (int n = m % 2 + 1; n < m; n += 2) {
                if (y % (m + n) == 0 && gcd(m, n) == 1) {
                    ++triples;
                }
            }
        }
        if (triples > maxTriples) {
            maxTriples = triples;
            result = p;
        }
    }
    return result;
}

int main()
{
    std::cout << "Answer: " << rightestTrianglePerimeter(1000) << '\n';
    return 0;
}
