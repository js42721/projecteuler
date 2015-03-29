#include <gmpxx.h>

#include <iostream>
#include <set>

int distinctPowers(int baseUpper, int expUpper)
{
    std::set<mpz_class> set;
    for (int base = 2; base <= baseUpper; ++base) {
        mpz_class pow = base;
        for (int exp = 2; exp <= expUpper; ++exp) {
            pow *= base;
            set.insert(pow);
        }
    }
    return set.size();
}

int main()
{
    std::cout << "Answer: " << distinctPowers(100, 100) << '\n';
    return 0;
}
