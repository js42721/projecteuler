#include <iostream>

int sumOfMatrixDiagonals(int n)
{
    // For any of the concentric squares, the sum of the corners is given by
    // n^2 + (n^2 - 3n + 3) + (n^2 - 2n + 2) + (n^2 - n + 1) = 4n^2 - 6n + 6
    // where n is the width of the square. The sum of the corners of all the
    // squares is the sum from 1 to (n - 1) / 2 of 4(2i + 1)^2 - 6(2i + 1) + 6
    // where n is the width of the entire matrix. That sum can be expressed as
    // 2k(k(8k + 15) + 13) / 3. Adding 1 for the center of the matrix gives the
    // sum of the diagonals.
    int k = (n - 1) / 2;
    return 2 * k * (k * (8 * k + 15) + 13) / 3 + 1;
}

int main()
{
    std::cout << "Answer: " << sumOfMatrixDiagonals(1001) << '\n';
    return 0;
}
