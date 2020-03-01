/*
动态规划
空间复杂度为 O(n)
*/
#include <algorithm>
using namespace std;
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int *dp = new int[n];
        fill(dp, dp + n, 0);
        dp[0] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};