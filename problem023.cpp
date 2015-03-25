#include <iostream>
#include <vector>

std::vector<int> aliquotSums(int upper)
{
    std::vector<int> s(upper + 1, 1);
    s[1] = 0;
    int end = upper / 2;
    for (int i = 2; i <= end; ++i) {
        for (int j = 2 * i; j <= upper; j += i) {
            s[j] += i;
        }
    }
    return s;
}

int nonabundantSums()
{
    int upper = 28123;
    std::vector<int> s = aliquotSums(upper);
    std::vector<int> abundant;
    for (int i = 1; i <= upper; ++i) {
        if (s[i] > i) {
            abundant.push_back(i);
        }
    }
    for (int i = 0; i < abundant.size(); ++i) {
        for (int j = i; j < abundant.size(); ++j) {
            int sum = abundant[i] + abundant[j];
            if (sum > upper) {
                break;
            }
            s[sum] = -1;
        }
    }
    int nonabundant = 0;
    for (int i = 1; i <= upper; ++i) {
        if (s[i] != -1) {
            nonabundant += i;
        }
    }
    return nonabundant;
}

int main()
{
    std::cout << "Answer: " << nonabundantSums() << '\n';
    return 0;
}
