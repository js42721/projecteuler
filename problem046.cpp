#include "lib/mathutils.h"

#include <cmath>
#include <iostream>
#include <vector>

int goldbachsOtherConjecture()
{
    for (int i = 9;; i += 2) {
        if (isPrime(i)) {
            continue;
        }
        bool wrong = true;
        int sub = 2;
        int inc = 6;
        do {
            if (isPrime(i - sub)) {
                wrong = false;
                break;
            }
            sub += inc;
            inc += 4;
        } while (sub < i);
        if (wrong) {
            return i;
        }
    }
}

int main()
{
    std::cout << "Answer: " << goldbachsOtherConjecture() << '\n';
    return 0;
}
