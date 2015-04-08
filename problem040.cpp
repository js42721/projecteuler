#include <cmath>
#include <iostream>

int champernowneNthDigit(int n)
{
    int digits = 0;
    int upperVal = 1;
    int upperIndex = 0;
    do {
        ++digits;
        upperIndex += 9 * upperVal * digits;
        upperVal *= 10;
    } while (n > upperIndex);
    int dist = upperIndex - n;
    int val = upperVal - dist / digits - 1;
    int div = pow(10, dist % digits);
    return val / div % 10;
}

int main()
{
    int ans = 1;
    int n = 1;
    for (int i = 0; i < 7; ++i) {
        ans *= champernowneNthDigit(n);
        n *= 10;
    }
    std::cout << "Answer: " << ans << '\n';
    return 0;
}
