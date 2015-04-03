#include <iostream>
#include <vector>

std::vector<int> digitFactorials()
{
    int fact[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
    std::vector<int> results;
    // The upper limit is 7 * 9! since the maximum number of digits is 7.
    for (int i = 3; i <= 2540160; ++i) {
        int x = i;
        int digitFactSum = 0;
        do {
            digitFactSum += fact[x % 10];
            x /= 10;
        } while (x != 0);
        if (digitFactSum == i) {
            results.push_back(i);
        }
    }
    return results;
}

int main()
{
    int ans = 0;
    std::vector<int> results = digitFactorials();
    for (int i = 0; i < results.size(); ++i) {
        ans += results[i];
    }
    std::cout << "Answer: " << ans << '\n';
    return 0;
}
