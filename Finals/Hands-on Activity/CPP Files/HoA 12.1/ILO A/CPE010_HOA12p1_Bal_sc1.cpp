#include <iostream>
#include <algorithm>

const int MAX = 1000;
int memo[MAX + 1];

int getMinSteps(int n)
{
    if (n == 1)
        return 0; // base case
    if (memo[n] != -1)
        return memo[n];             // we have solved it already :)
    int r = 1 + getMinSteps(n - 1); // '-1' step . 'r' will contain the optimal answer finally
    if (n % 2 == 0)
        r = std::min(r, 1 + getMinSteps(n / 2)); // '/2' step
    if (n % 3 == 0)
        r = std::min(r, 1 + getMinSteps(n / 3)); // '/3' step
    memo[n] = r;                                 // save the result. If you forget this step, then its same as plain recursion.
    return r;
}

int main()
{
    int n = 27;
    for (int i = 0; i <= MAX; i++)
    {
        memo[i] = -1;
    }

    std::cout << "N: " << n << '\n';
    std::cout << "Minimum number of steps: " << getMinSteps(n) << '\n';

    return 0;
}
