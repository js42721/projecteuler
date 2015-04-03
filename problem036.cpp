#include <iostream>
#include <vector>

bool isPalindrome(int n)
{
    int reverse = 0;
    int x = n;
    while (x != 0) {
        reverse = 10 * reverse + x % 10;
        x /= 10;
    }
    return reverse == n;
}

std::vector<int> doubleBasePalindromes(int upper)
{
    std::vector<int> results;
    int i = 1;
    // Generates all binary palindromes up to the upper limit.
    for (;;) {
        int reverse = 0;
        int len = 0;
        int x = i;
        do {
            reverse = (reverse << 1) | (x & 1);
            x >>= 1;
            ++len;
        } while (x != 0);
        int even = (i << len) | reverse;
        int odd  = (i << (len - 1)) | reverse;
        if (even <= upper) {
            if (isPalindrome(even)) {
                results.push_back(even);
            }
            if (isPalindrome(odd)) {
                results.push_back(odd);
            }
        } else if (odd <= upper) {
            if (isPalindrome(odd)) {
                results.push_back(odd);
            }
        } else {
            break;
        }
        ++i;
    }
    return results;
}

int main()
{
    int ans = 0;
    std::vector<int> results = doubleBasePalindromes(999999);
    for (int i = 0; i < results.size(); ++i) {
        ans += results[i];
    }
    std::cout << "Answer: " << ans << '\n';
    return 0;
}
