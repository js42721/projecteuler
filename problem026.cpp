#include "lib/mathutils.h"

#include <iostream>

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
