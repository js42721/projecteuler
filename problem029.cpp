#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

int gcd(int a, int b)
{
    while (b != 0) {
        int c = b;
        b = a % b;
        a = c;
    }
    return abs(a);
}

int lcm(int a, int b)
{
    return abs(b / gcd(a, b) * a);
}

int distinctPowers(int baseUpper, int expUpper)
{
    // All perfect powers of the same degree have an equal amount of duplicates
    // in their raised powers while numbers that are not perfect powers have
    // distinct powers. The highest perfect power will be a power of 2 so
    // counting duplicates for powers of 2 is enough to cover all bases.
    int len = log2(baseUpper) + 1;
    std::vector<int> frequency(len);
    std::vector<int> duplicates(len);
    int sqrtBaseUpper = sqrt(baseUpper);
    std::vector<bool> skip(sqrtBaseUpper + 1);
    // Computes the size of each perfect power group.
    for (int i = 2; i <= sqrtBaseUpper; ++i) {
        if (skip[i]) {
            continue;
        }
        int power = i * i;
        int degree = 2;
        while (power <= baseUpper) {
            if (power <= sqrtBaseUpper) {
                skip[power] = true;
            }
            ++frequency[degree];
            ++degree;
            power *= i;
        }
    }
    // Counts duplicates for each group.
    for (int i = 2; i < len; ++i) {
        std::vector<bool> discovered(expUpper + 2);
        for (int j = 1; j < i; ++j) {
            int inc = lcm(i, j) / i;
            int pos = std::max(2, inc);
            int limit = expUpper * j / i;
            while (pos <= limit) {
                if (!discovered[pos]) {
                    ++duplicates[i];
                    discovered[pos] = true;
                }
                pos += inc;
            }
        }
    }
    int duplicateCount = 0;
    for (int i = 2; i < len; ++i) {
        duplicateCount += frequency[i] * duplicates[i];
    }
    return (baseUpper - 1) * (expUpper - 1) - duplicateCount;
}

int main()
{
    std::cout << "Answer: " << distinctPowers(100, 100) << '\n';
    return 0;
}
