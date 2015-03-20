#include <algorithm>
#include <iostream>

long long latticePaths(int width, int height)
{
    long long paths = 1;
    int n = width + height;
    int k = std::min(width, height);
    // Binomial coefficient.
    for (int i = 0; i < k; ++i) {
        paths = paths * (n - i) / (i + 1);
    }
    return paths;
}

int main()
{
    std::cout << "Answer: " << latticePaths(20, 20) << '\n';
    return 0;
}
