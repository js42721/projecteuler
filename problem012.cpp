#include <cmath>
#include <iostream>

int factors(int n)
{
    // The factors of an integer can be counted by adding 1 to each of the
    // exponents in its prime factorization and then multiplying the results.
    // For example, 1000 = 2^3 * 5^3, so there are (3 + 1) * (3 + 1) factors.
    if (n < 1) {
        return -1;
    }
    int a[] = { 2, 3, 5 };
    int result = 1;
    int x = n;
    for (int i = 0; i < 3; ++i) {
        int factor = a[i];
        int k = 0;
        while (x % factor == 0) {
            x /= factor;
            ++k;
        }
        result *= k + 1;
        if (x == 1) {
            return result;
        }
    }
    int inc[] = { 4, 2, 4, 2, 4, 6, 2, 6 };
    int idx = 0;
    int factor = 7;
    int sqrtX = sqrt(x);
    int k = 0;
    while (factor <= sqrtX) {
        if (x % factor == 0) {
            x /= factor;
            sqrtX = sqrt(x);
            ++k;
        } else {
            factor += inc[idx];
            idx = (idx + 1) % 8;
            result *= k + 1;
            k = 0;
        }
    }
    if (x == factor) {
        result *= k + 2;
    } else {
        result *= 2 * (k + 1);
    }
    return result;
}

int triangle(int minFactors)
{
    // The nth triangular number is n * (n + 1) / 2. Because the consecutive
    // numbers n and n + 1 are coprime, we can use the following property of
    // the divisor function:
    //
    // d(a * b) = d(a) * d(b) if gcd(a, b) = 1
    //
    // Keeping in mind the fact that we can remove factors of 2 from the even
    // element of an even-odd coprime pair and still have a coprime pair, we
    // can see that the following is true:
    //  
    // d(n * (n + 1) / 2) = d(n / 2) * d(n + 1) if n is even, or
    //                      d(n) * d((n + 1) / 2) if n + 1 is even
    int i = 1;
    int current = 1;
    int next = 1;
    while (current * next < minFactors) {
        current = next;
        if (++i % 2 == 0) {
            next = factors(i + 1);
        } else {
            next = factors((i + 1) / 2);
        }
    }
    return i * (i + 1) / 2;
}

int main()
{
    std::cout << "Answer: " << triangle(501) << '\n';
    return 0;
}
