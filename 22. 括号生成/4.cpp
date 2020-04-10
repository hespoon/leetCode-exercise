/*
动态规划
状态定义
设状态数组 vector<vector<string>> dp，dp[i] 表示 i 对括号的所有合法组合
dp[0] 为空的 vector<string>，dp[1]={"()"}
状态转移
n 对括号的合法组合一定是 (a)b，其中 a 是 k 对括号的所有合法组合，b 是 n-1-k 对括号的所有合法组合，k∈[0,n-1]
因此，dp[i]=(dp[k])dp[n-1-k]，k∈[0,n-1]
此时，dp[i] 与之前的 dp[0,i-1] 都有关系，所以 dp 数组不能压缩为一个元素
这种 dp 比较快
*/
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<vector<string>> dp(n + 1, vector<string>()); // 状态数组
        dp[1].push_back("()");
        for (int i = 2; i <= n; i++)
        { // 计算 dp 数组
            for (int j = 0; j <= i - 1; j++)
            {
                vector<string> tt; // 计算 (a)b，a 为 j 对括号的所有合法组合，b 为 i-j-1 对括号的所有合法组合
                int t = i - 1 - j;
                int len1 = dp[j].size(), len2 = dp[t].size();
                if (len1 == 0)
                {
                    tt.push_back("()");
                }
                else
                {
                    for (int k = 0; k < len1; k++)
                    {
                        tt.push_back("(" + dp[j][k] + ")");
                    }
                }
                int len3 = tt.size();
                if (len2 != 0)
                {
                    vector<string> temp;
                    for (int k = 0; k < len3; k++)
                    {
                        for (int l = 0; l < len2; l++)
                        {
                            temp.push_back(tt[k] + dp[t][l]);
                        }
                    }
                    tt.clear();
                    tt = move(temp);
                }
                for (int k = 0; k < tt.size(); k++)
                {
                    dp[i].push_back(tt[k]);
                }
            }
        }
        return dp[n];
    }
};