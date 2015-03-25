#include <iostream>
#include <vector>

std::vector<int> nthPermutation(int n, int elements)
{
    std::vector<int> a(elements);
    int x = n;
    // Converts n to factoradic to obtain a Lehmer code.
    for (int i = 2; i <= elements; ++i) {
        a[elements - i] = x % i;
        x /= i;
    }
    // Decodes the Lehmer code into a permutation.
    for (int i = elements - 2; i >= 0; --i) {
        for (int j = i + 1; j < elements; ++j) {
            if (a[j] >= a[i]) {
                ++a[j];
            }
        }
    }
    return a;
}

int main()
{
    std::vector<int> ans = nthPermutation(999999, 10);
    for (int i = 0; i < ans.size(); ++i) {
        std::cout << ans[i];
    }
    std::cout << '\n';
    return 0;
}
