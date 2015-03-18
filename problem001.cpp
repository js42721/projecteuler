#include <iostream>

int sumOfMultiples(int n, int upper)
{
    // n + 2n + 3n + ... + p = n * (1 + 2 + 3 + ... + (p / n))
    //                       = n * ((p / n) * ((p / n) + 1) / 2)
    int k = upper / n;
    return n * (k * (k + 1) / 2);
}

int main()
{
    // Multiples of 15 are redundant, being multiples of both 3 and 5.
    int ans = sumOfMultiples(3, 999) + sumOfMultiples(5, 999) - sumOfMultiples(15, 999);
    std::cout << "Answer: " << ans << '\n';
    return 0;
}
