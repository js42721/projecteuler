#include "lib/mathutils.h"

#include <iostream>
#include <utility>
#include <vector>

std::vector<std::pair<int, int> > curiousFractions()
{
    // The only fractions that need to be considered are those where the right
    // digit of the numerator is equal to the left digit of the denominator.
    std::vector<std::pair<int, int> > results;
    for (int x = 1; x <= 9; ++x) {
        for (int nl = 1; nl <= x; ++nl) {
            for (int dr = nl + 1; dr <= 9; ++dr) {
                int n = 10 * nl + x;
                int d = 10 * x + dr;
                if (nl * d == dr * n) {
                    results.push_back(std::make_pair(n, d));
                }
            }
        }
    }
    return results;
}

int main()
{
    std::vector<std::pair<int, int> > results = curiousFractions();
    int n = 1, d = 1;
    for (int i = 0; i < results.size(); ++i) {
        n *= results[i].first;
        d *= results[i].second;
    }
    int ans = d / gcd(n, d);
    std::cout << "Answer: " << ans << '\n';
    return 0;
}
