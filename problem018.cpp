#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

int maximumPathSum(std::vector<int> triangle)
{
    int height = sqrt(2 * triangle.size());
    for (int i = height - 2; i >= 0; --i) {
        int start = i * (i + 1) / 2;
        int end = start + i;
        for (int j = start; j <= end; ++j) {
            triangle[j] += std::max(triangle[j + i + 1], triangle[j + i + 2]);
        }
    }
    return triangle[0];
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
        return 1;
    }
    std::vector<int> triangle;
    int x;
    while (file >> x) {
        triangle.push_back(x);
    }
    std::cout << "Answer: " << maximumPathSum(triangle) << '\n';
    return 0;
}
