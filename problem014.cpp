#include <iostream>
#include <vector>

int longestCollatz(int upper)
{
    // Only numbers up to the upper limit are memoized since terms in a
    // sequence can get large.
    std::vector<int> mem(upper + 1, 0);
    std::vector<int> chain;
    mem[1] = 1;
    int ret = -1;
    int longest = 0;
    for (int i = 2; i <= upper; ++i) {
        int size = mem[i];
        if (size == 0) {
            long long x = i;
            do {
                if (x <= upper) {
                    chain.push_back(x);
                    mem[x] = size;
                }
                if (x % 2 == 0) {
                    x /= 2;
                } else {
                    x = 3 * x + 1;
                }
                ++size;
            } while (x > upper || mem[x] == 0);
            size += mem[x];
            for (int j = 0; j < chain.size(); ++j) {
                int index = chain[j];
                mem[index] = size - mem[index];
            }
            chain.clear();
        }
        if (size > longest) {
            longest = size;
            ret = i;
        }
    }
    return ret;
}

int main()
{
    std::cout << "Answer: " << longestCollatz(1000000) << '\n';
    return 0;
}
