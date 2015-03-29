#include <iostream>
#include <vector>

int waysToChangeMoney(int amount)
{
    int denom[] = { 1, 2, 5, 10, 20, 50, 100, 200 };
    int denomLen = sizeof(denom) / sizeof(denom[0]);
    std::vector<int> mem(amount + 1);
    mem[0] = 1;
    for (int i = 0; i < denomLen; ++i) {
        for (int j = denom[i]; j <= amount; ++j) {
            int difference = j - denom[i];
            mem[j] += mem[difference];
        }
    }
    return mem[amount];
}

int main()
{
    std::cout << "Answer: " << waysToChangeMoney(200) << '\n';
    return 0;
}
