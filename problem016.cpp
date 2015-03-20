#include <cmath>
#include <iostream>
#include <vector>

int sumOfDecimalDigits(const std::vector<bool>& bits)
{
    // Double dabble algorithm for converting binary to binary-coded decimal.
    std::vector<char> s(ceil(bits.size() / 3.0));
    int pos = s.size() - 1;
    for (int i = 0; i < bits.size(); ++i) {
        for (int j = pos; j < s.size(); ++j) {
            if (s[j] >= 5) {
                s[j] += 3;
            }
        }
        if ((s[pos] & 0x8) != 0) {
            --pos;
        }
        for (int j = pos; j < s.size() - 1; ++j) {
            s[j] <<= 1;
            s[j] &= 0xf;
            s[j] |= ((s[j + 1] & 0x8) != 0);
        }
        s[s.size() - 1] <<= 1;
        s[s.size() - 1] &= 0xf;
        s[s.size() - 1] |= bits[i];
    }
    int sum = 0;
    for (int i = pos; i < s.size(); ++i) {
        sum += s[i];
    }
    return sum;
}

int main()
{
    std::vector<bool> bits(1001);
    bits[0] = true;
    std::cout << "Answer: " << sumOfDecimalDigits(bits) << '\n';
    return 0;
}
