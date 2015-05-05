#include <cmath>
#include <iostream>

bool isPentagonal(long long n)
{
    return fmod(sqrt(24 * n + 1), 6) == 5;
}

int nextTriPentaHexagonal(int n)
{
    int hexIndex = (sqrt(8 * n + 1) + 1) / 4;
    int hex = hexIndex * (2 * hexIndex - 1);
    int inc = 4 * hexIndex + 1;
    for (;;) {
        hex += inc;
        if (isPentagonal(hex)) {
            return hex;
        }
        inc += 4;
    }
}

int main()
{
    std::cout << "Answer: " << nextTriPentaHexagonal(40755) << '\n';
    return 0;
}
