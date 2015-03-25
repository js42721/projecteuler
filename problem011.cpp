#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

int productHelper(const std::vector<int>& a, int n, int index, int step)
{
    int product = a[index];
    for (int i = 1; i < n; ++i) {
        product *= a[index + i * step];
    }
    return product;
}

int largestGridProduct(const std::vector<int>& a, int cols, int rows, int n)
{
    int max = 0;
    int xEnd = cols - n + 1;
    int yEnd = rows - n + 1;
    for (int y = 0; y < yEnd; ++y) {
        for (int x = 0; x < xEnd; ++x) {
            int index = y * cols + x;
            max = std::max(max, productHelper(a, n, index, 1)); // East.
            max = std::max(max, productHelper(a, n, index, cols)); // South.
            max = std::max(max, productHelper(a, n, index, cols + 1)); // Southeast.
            max = std::max(max, productHelper(a, n, index + n - 1, cols - 1)); // Southwest.
        }
    }
    for (int y = yEnd; y < rows; ++y) {
        for (int x = 0; x < xEnd; ++x) {
            int index = y * cols + x;
            max = std::max(max, productHelper(a, n, index, 1)); // East.
        }
    }
    for (int y = 0; y < yEnd; ++y) {
        for (int x = xEnd; x < cols; ++x) {
            int index = y * cols + x;
            max = std::max(max, productHelper(a, n, index, cols)); // South.
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
    std::vector<int> a;
    std::string line;
    int rows = 0;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int x;
        while (iss >> x) {
            a.push_back(x);
        }
        ++rows;
    }
    int cols = a.size() / rows;
    std::cout << "Answer: " << largestGridProduct(a, cols, rows, 4) << '\n';
    return 0;
}
