#include <iostream>
#include <vector>

std::vector<int> digitFifthPowers()
{
    int d[] = { 0, 1, 32, 243, 1024, 3125, 7776, 16807, 32768, 59049 };
    std::vector<int> results;
    // The desired numbers have 6 digits at most since numbers with n > 6
    // digits would be too large to represent as a sum of n fifths. The largest
    // possible 6-digit sum of fifths is 6 * 9^5 so that is the upper bound.
    for (int i = 2; i <= 354294; ++i) {
        int x = i;
        int digitFifthSum = 0;
        do {
            digitFifthSum += d[x % 10];
            x /= 10;
        } while (x != 0);
        if (digitFifthSum == i) {
            results.push_back(i);
        }
    }
    return results;
}

int main()
{
    int ans = 0;
    std::vector<int> results = digitFifthPowers();
    for (int i = 0; i < results.size(); ++i) {
        ans += results[i];
    }
    std::cout << "Answer: " << ans << '\n';
    return 0;
}
