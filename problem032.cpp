#include <iostream>
#include <set>

bool isPandigital(int n)
{
    if (n < 123456789 || n > 987654321) {
        return false;
    }
    int bits = 0;
    do {
        bits |= 1 << (n % 10);
        n /= 10;
    } while (n != 0);
    return bits == 0x3fe;
}

int concatenate(int a, int b)
{
    int x = a, y = b;
    while (y != 0) {
        y /= 10;
        x *= 10;
    }
    return x + b;
}

std::set<int> unusualPandigitals()
{
    std::set<int> results;
    for (int i = 2; i <= 99; ++i) {
        int start = (i >= 10) ? 100 : 1000;
        int end = 9999 / i;
        for (int j = start; j <= end; ++j) {
            int rhs = i * j;
            int lhs = concatenate(i, j);
            int cat = concatenate(lhs, rhs);
            if (isPandigital(cat)) {
                results.insert(rhs);
            }
        }
    }
    return results;
}

int main()
{
    int ans = 0;
    std::set<int> results = unusualPandigitals();
    for (std::set<int>::iterator i = results.begin(); i != results.end(); ++i) {
        ans += *i;
    }
    std::cout << "Answer: " << ans << '\n';
    return 0;
}
