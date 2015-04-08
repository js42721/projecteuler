#include "lib/mathutils.h"

#include <iostream>

int multiplicativeOrder(int base, int n)
{
    if (n == 1 || gcd(base, n) != 1) {
        return 0;
    }
    int order = 1;
    int powMod = base;
    while (powMod != 1) {
        powMod = (powMod * base) % n;
        ++order;
    }
    return order;
}

int longestReciprocalCycle(int upper)
{
    // See http://mathforum.org/library/drmath/view/67018.html.
    int longestPeriod = 0;
    int result = 1;
    int i = upper;
    while (i > longestPeriod) {
        int x = i;
        int y = gcd(x, 10);
        while (y != 1) {
            x /= y;
            y = gcd(x, 10);
        }
        int period = multiplicativeOrder(10, x);
        if (period > longestPeriod) {
            longestPeriod = period;
            result = i;
        }
        --i;
    }
    return result;
}

int main()
{
    std::cout << "Answer: " << longestReciprocalCycle(1000) << '\n';
    return 0;
}
