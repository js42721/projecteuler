#include <cmath>
#include <iostream>
#include <vector>

long long sumOfPrimes(int upper)
{
    if (upper <= 1) {
        return 0;
    }
    int end = (upper - 1) / 2;
    std::vector<char> a(end + 1, 1);
    int sqrtLimit = (sqrt(upper) - 1) / 2;
    // Sieve of Eratosthenes.
    for (int i = 1; i <= sqrtLimit; ++i) {
        if (a[i]) {
            for (int j = 2 * i * (i + 1); j <= end; j += 2 * i + 1) {
                a[j] = 0;
            }
        }
    }
    long long sum = 2;
    for (int i = 1; i <= end; ++i) {
        if (a[i]) {
            sum += 2 * i + 1;
        }
    }
    return sum;
}

int main()
{
    std::cout << "Answer: " << sumOfPrimes(1999999) << '\n';
    return 0;
}
