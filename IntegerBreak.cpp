/*
 * Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.
 * Return the maximum product you can get.
 */
#include <vector>
using namespace std;

int integerBreak(int n)
{
    if (n == 2)
        return 1;
    if (n == 3)
        return 2;
    vector<int> dp(n + 1, 1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = max(dp[i], i);
        for (int k = 1; k < i; ++k)
        {
            dp[i] = max(dp[i], k * dp[i - k]);
        }
    }
    return dp[n];
}
