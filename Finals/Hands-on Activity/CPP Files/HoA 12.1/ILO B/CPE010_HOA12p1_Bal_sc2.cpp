
#include <iostream>
#include <algorithm>

const int MAX = 1000;
int dp[MAX + 1];

int getMinSteps(int n)
{
    dp[1] = 0; // trivial case
    for (int i = 2; i <= n; i++)
    {
        dp[i] = 1 + dp[i - 1];
        if (i % 2 == 0)
            dp[i] = std::min(dp[i], 1 + dp[i / 2]); // "/2" step
        if (i % 3 == 0)
            dp[i] = std::min(dp[i], 1 + dp[i / 3]); // "/3" step
    }
    return dp[n];
}

int main()
{
    int n = 27;

    std::cout << "N: " << n << '\n';
    std::cout << "Minimum number of steps: " << getMinSteps(n) << '\n';

    return 0;
}
