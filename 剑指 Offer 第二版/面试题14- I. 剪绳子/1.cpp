/*
动态规划
状态定义：dp[i] 表示长度为 i 的绳子剪成若干段后，各段长度乘积的最大值。
状态转移：dp[0]=0，dp[1]=1，dp[2]=2，dp[3]=3，dp[i]=max(dp[j]*dp[i-j])，1 ≤ j ≤ i/2，i≥4；
         i={0,1,2,3} 时，不需要剪，否则会使乘积变小。
i 必须大于等于 4 才能使用上述状态转移方程。i={0,1,2,3} 时不符合上述状态的定义，需要单独计算。
i 的值不能太大，否则 dp[i] 会超出 int 的表示范围，甚至会超出 long long 的表示范围
*/
#include <vector>
using namespace std;
int cuttingRope(int n)
{
    if (n < 2)
        return 0;
    if (n == 2)
        return 1;
    if (n == 3)
        return 2;
    int ans = 0x80000000;
    vector<long long> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i <= n; i++)
    {
        long long MAX = 0;
        for (int j = 1; j <= i / 2; j++)
        {
            long long pro = dp[j] * dp[i - j];
            if (pro > MAX)
                MAX = pro;
        }
        dp[i] = MAX;
    }
    ans = (int)dp[n];
    return ans;
}