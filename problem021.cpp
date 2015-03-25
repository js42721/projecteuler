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

int sumOfAmicableNumbers(int upper)
{
    std::vector<int> s = aliquotSums(upper);
    int amis = 0;
    for (int i = 2; i <= upper; ++i) {
        int sum = s[i];
        if (sum > i && sum <= upper && s[sum] == i) {
            amis += sum + i;
        }
    }
    return amis;
}

int main()
{
    std::cout << "Answer: " << sumOfAmicableNumbers(9999) << '\n';
    return 0;
}
