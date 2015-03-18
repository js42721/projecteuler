// Compile with the following command:
// g++ problem13.cpp -lgmpxx -lgmp

#include <gmpxx.h>

#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <input>\n";
        return 0;
    }
    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Cannot open " << argv[1] << '\n';
        return 1;
    }
    mpz_class sum;
    std::string line;
    while (std::getline(file, line)) {
        mpz_class x = mpz_class(line);
        sum += x;
    }
    std::string ans(sum.get_str(), 0, 10);
    std::cout << "Answer: " << ans << '\n';
    return 0;
}
