#include <iostream>
#include <vector>

bool hasUniqueDigits(long long n)
{
    long long x = n;
    int bits = 0;
    do {
        int b = 1 << (x % 10);
        if ((bits & b) != 0) {
            return false;
        }
        bits |= b;
        x /= 10;
    } while (x != 0);
    return true;
}

std::vector<long long> interestingPandigitals()
{
    int d[] = { 13, 11, 7, 5, 3, 2, 1 };
    std::vector<long long> vec;
    for (int i = 17; i <= 986; i += 17) {
        if (hasUniqueDigits(i)) {
            vec.push_back(i);
        }
    }
    long long m = 10;
    std::vector<long long> next;
    for (int i = 0; i < 7; ++i) {
        int divisor = d[i];
        for (int j = 0; j < vec.size(); ++j) {
            long long val = vec[j];
            for (int k = 0; k <= 900; k += 100) {
                int substr = k + val / m;
                if (substr % divisor == 0) {
                    long long nextVal = m * k + val;
                    if (hasUniqueDigits(nextVal)) {
                        next.push_back(nextVal);
                    }
                }
            }
        }
        vec.swap(next);
        next.clear();
        m *= 10;
    }
    std::vector<long long> results;
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] > 1000000000) {
            results.push_back(vec[i]);
        }
    }
    return results;
}

int main()
{
    long long ans = 0;
    std::vector<long long> results = interestingPandigitals();
    for (int i = 0; i < results.size(); ++i) {
        ans += results[i];
    }
    std::cout << "Answer: " << ans << '\n';
    return 0;
}
