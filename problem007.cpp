#include <cmath>
#include <iostream>
#include <vector>

int nthPrime(int n)
{
    // The upper bound for n >= 6 is from the paper "The kth prime is greater 
    // than k(ln k + ln ln k - 1) for k >= 2" by Pierre Dusart.
    int upper = (n >= 6) ? n * (log(n) + log(log(n))) : 11;
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
    int ret = -1;
    int c = 1;
    for (int i = 1; i <= end; ++i) {
        if (a[i] && ++c == n) {
            return 2 * i + 1;
        }
    }
    return (n == 1) ? 2 : ret;
}

int main()
{
    std::cout << "Answer: " << nthPrime(10001) << '\n';
    return 0;
}
