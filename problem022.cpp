#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int alphabeticalValue(const std::string& name)
{
    int val = 0;
    for (int i = 0; i < name.size(); ++i) {
        val += name[i] - 'A' + 1;
    }
    return val;
}

int nameScoreTotal(std::vector<std::string> names)
{
    std::sort(names.begin(), names.end());
    int total = 0;
    for (int i = 0; i < names.size(); ++i) {
        int score = alphabeticalValue(names[i]) * (i + 1);
        total += score;
    }
    return total;
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
    std::vector<std::string> names;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;
        while (std::getline(iss, token, ',')) {
            names.push_back(token.substr(1, token.size() - 2));
        }
    }
    std::cout << "Answer: " << nameScoreTotal(names) << '\n';
    return 0;
}
