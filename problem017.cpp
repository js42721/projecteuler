#include <iostream>

// Only works for 1 <= n <= 1000.
int lettersInNumber(int n)
{
    if (n == 1000) {
        return 11;
    }
    // 1, 2, 3, ... 19
    int a[20] = { 0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 5, 8, 8, 8, 7, 9, 8, 8 };
    // 20, 30, 40, ... 90
    int b[10] = { 0, 0, 6, 6, 5, 5, 5, 7, 6, 6 };
    int d2 = n / 100 % 10;
    int d1 = n / 10 % 10;
    int d0 = n % 10;
    int letters = 0;
    if (d2 > 0) {
        letters += a[d2] + 7;
        if (d0 > 0 || d1 > 0) {
            letters += 3; // "and"
        }
    }
    if (d1 > 1) {
        letters += b[d1] + a[d0];
    } else {
        letters += a[10 * d1 + d0];
    }
    return letters;
}

int main()
{
    int ans = 0;
    for (int i = 1; i <= 1000; ++i) {
        ans += lettersInNumber(i);
    }
    std::cout << "Answer: " << ans << '\n';
    return 0;
}
