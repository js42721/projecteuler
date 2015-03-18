#include <iostream>

int squareOfSum(int n)
{
    int sum = n * (n + 1) / 2;
    return sum * sum;
}

int sumOfSquares(int n)
{
    return n * (n + 1) * (2 * n + 1) / 6;
}

int main()
{
    std::cout << "Answer: " << squareOfSum(100) - sumOfSquares(100) << '\n';
    return 0;
}
