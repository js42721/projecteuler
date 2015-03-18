#include <cmath>
#include <iostream>
#include <vector>

std::vector<int> primes(int upper)
{
    std::vector<int> ret;
    if (upper <= 1) {
        return ret;
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
    ret.push_back(2);
    for (int i = 1; i <= end; ++i) {
        if (a[i]) {
            ret.push_back(2 * i + 1);
        }
    }
    return ret;
}

int lcmOfRange(int upper)
{
    int ret = 1;
    int sqrtUpper = sqrt(upper);
    std::vector<int> p = primes(upper);
    for (int i = 0; i < p.size(); ++i) {
        int x;
        int product = p[i];
        do {
            x = product;
            product *= p[i];
        } while (product <= upper);
        ret *= x; // x = p_i^(log_p_i(upper))
    }
    return ret;
}

int main()
{
    std::cout << "Answer: " << lcmOfRange(20) << '\n';
    return 0;
}
