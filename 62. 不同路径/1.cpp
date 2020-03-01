/*
动态规划
空间复杂度为 O(n^2)
*/
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int **dp = new int *[m];
        for (int i = 0; i < m; i++)
        {
            dp[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = 0;
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                }
                if (i > 0)
                {
                    dp[i][j] += dp[i - 1][j];
                }
                if (j > 0)
                {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};