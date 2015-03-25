#include <gmpxx.h>

#include <iostream>

int factorialDigitSum(int n)
{
    mpz_class factorial;
    mpz_fac_ui(factorial.get_mpz_t(), n);
    std::string digits = factorial.get_str();
    int sum = 0;
    for (int i = 0; i < digits.size(); ++i) {
        sum += digits[i] - '0';
    }
    return sum;
}

int main()
{
    std::cout << "Answer: " << factorialDigitSum(100) << '\n';
    return 0;
}
