#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

bool isTriangleNumber(int n)
{
    int x = 8 * n + 1;
    return x % 2 != 0 && fmod(sqrt(x), 1) == 0;
}

int wordValue(const std::string& word)
{
    int result = 0;
    for (int i = 0; i < word.size(); ++i) {
        result += word[i] - 'A' + 1;
    }
    return result;
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
    int ans = 0;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;
        while (std::getline(iss, token, ',')) {
            std::string word = token.substr(1, token.size() - 2);
            if (isTriangleNumber(wordValue(word))) {
                ++ans;
            }
        }
    }
    std::cout << "Answer: " << ans << '\n';
    return 0;
} 
