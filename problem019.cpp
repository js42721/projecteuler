#include <iostream>

// Originally posted by Tomohiko Sakamoto on the comp.lang.c Usenet newsgroup.
int dayOfWeek(int y, int m, int d)
{
    int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}

int main()
{
    int ans = 0;
    for (int y = 1901; y <= 2000; ++y) {
        for (int m = 1; m <= 12; ++m) {
            if (dayOfWeek(y, m, 1) == 0) {
                ++ans;
            }
        }
    }
    std::cout << "Answer: " << ans << '\n';
    return 0;
}
