/*
动态规划
状态数组定义
dp[i] 表示以 nums[i] 结尾的连续子数组可取到的最大和
状态转移方程
dp[i] = dp[i-1] > 0 ? dp[i-1] + nums[i] : nums[i]
dp[0] = nums[0]
*/
#include <vector>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int ans = dp[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = dp[i - 1] > 0 ? dp[i - 1] + nums[i] : nums[i];
            ans = ans > dp[i] ? ans : dp[i];
        }
        return ans;
    }
};