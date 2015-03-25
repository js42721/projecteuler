#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

long long nextRun(const std::string& n, int digits, int* pos)
{
    long long product = 1;
    int c = 0;
    int i = *pos;
    for (; i < n.size(); ++i) {
        if (n[i] == '0') {
            product = 1;
            c = 0;
        } else {
            product *= n[i] - '0';
            if (++c == digits) {
                break;
            }
        }
    }
    *pos = i;
    return (c < digits) ? 0 : product;
}

long long greatestProduct(const std::string& n, int digits)
{
    int i = 0;
    long long current = nextRun(n, digits, &i);
    long long max = current;
    ++i;
    for (; i < n.size(); ++i) {
        if (n[i] == '0') {
            current = nextRun(n, digits, &i);
        } else {
            current /= n[i - digits] - '0';
            current *= n[i] - '0';
        }
        if (current > max) {
            max = current;
        }
    }
    return max;
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <input>\n";
        return 0;
    }
    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Cannot open " << argv[1] << '\n';
        return EXIT_FAILURE;
    }
    file.seekg(0, std::ios_base::end);
    int bytes = file.tellg();
    file.seekg(0, std::ios_base::beg);
    std::string n;
    n.reserve(bytes);
    std::string line;
    while (std::getline(file, line)) {
        n.append(line);
    }
    std::cout << "Answer: " << greatestProduct(n, 13) << '\n';
    return 0;
}
