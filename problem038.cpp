#include <iostream>

bool isPandigital(int n)
{
    int bits = 0;
    while (n != 0) {
        bits |= 1 << (n % 10);
        n /= 10;
    }
    return bits == 0x3fe;
}

int largestPandigitalMultiple()
{
    for (int i = 9876;; --i) {
        int cat = 100000 * i + 2 * i;
        if (isPandigital(cat)) {
            return cat;
        }
    }
}

int main()
{
    std::cout << "Answer: " << largestPandigitalMultiple() << '\n';
    return 0;
}
