#include <cmath>
#include <iostream>

int palindromize(int n, bool oddLength)
{
    int x = n;
    if (oddLength) {
        x /= 10;
    }
    int mult = 1;
    int reverse = 0;
    while (x != 0) {
        reverse = 10 * reverse + x % 10;
        x /= 10;
        mult *= 10;
    }
    return mult * n + reverse;
}

int largestPalindromicProduct(int n)
{
    int lower = pow(10, n - 1);
    int upper = pow(10, n) - 1;
    for (int i = upper - 2; i >= lower; --i) {
        int p = palindromize(i, false);
        int sqrtP = sqrt(p);
        for (int j = upper; j >= sqrtP; --j) {
            if (p % j == 0) {
                return p;
            }
        }
    }
    for (int i = upper; i >= lower; --i) {
        int p = palindromize(i, true);
        int sqrtP = sqrt(p);
        for (int j = lower; j <= sqrtP; ++j) {
            if (p % j == 0) {
                return p;
            }
        }
    }
    return -1;
}

int main()
{
    std::cout << "Answer: " << largestPalindromicProduct(3) << '\n';
    return 0;
}
