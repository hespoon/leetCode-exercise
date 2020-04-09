/*
编辑操作有三种：插入一个字符、删除一个字符、替换一个字符
设要计算的两个字符串为 s1，s2。
对应的三种操作为：在 s1 中插入一个字符，在 s2 中插入一个字符，将 s1 中的字符替换（或将 s2 中的字符替换）
自底向上的动态规划
状态定义：
dp[i][j] 表示 s1[0,i-1] 和 s2[0,j-1] 两者的最短编辑距离。
状态数组的下标与字符串的下标差一，因为初始化时要用一个空字符串。
0 ≤ i ≤ s1.length()，0 ≤ j ≤ s2.length()
dp[0][j] 表示空字符串与 s2[0,j-1] 之间的编辑距离，明显，dp[0][j]=j，0 ≤ j ≤ s2.length()
同理，dp[i][0]=i，0 ≤ i ≤ s1.length()
状态转移方程：
dp[i][j] = min(dp[i-1][j-1],dp[i-1][j]+1,dp[i][j-1])，此时，s1[i-1]==s2[j-1]
或 dp[i][j] = min(dp[i-1][j-1]+1,dp[i-1][j]+1,dp[i][j-1])，此时，s1[i-1]!=s2[j-1]
*/
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int len1 = word1.length(), len2 = word2.length();
        if (len1 == 0)
            return len2;
        if (len2 == 0)
            return len1;
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0)); // 状态数组
        int i = 0, j = 0;
        while (i <= len1) // 状态数组初始化，计算空字符串与 word1[0,i-1] 的最短编辑距离
        {
            dp[i][0] = i;
            i++;
        }
        while (j <= len2) // 状态数组初始化，计算空字符串与 word2[0,j-1] 的最短编辑距离
        {
            dp[0][j] = j;
            j++;
        }
        for (i = 1; i <= len1; i++) // 填充状态数组
        {
            for (j = 1; j <= len2; j++)
            {
                int t1, t2, t3;
                if (word1[i - 1] == word2[j - 1])
                {
                    t1 = dp[i - 1][j - 1]; // 不变
                    t2 = dp[i - 1][j] + 1; // 在 word1[i-1] 前插入 word2[j-1]
                    t3 = dp[i][j - 1] + 1; // 在 word2[j-1] 前插入 word1[i-1]
                    dp[i][j] = min(t1, min(t2, t3));
                }
                else
                {

                    t1 = dp[i][j - 1];     // 在 word2[j-1] 前插入 word1[i-1]
                    t2 = dp[i - 1][j];     // 在 word1[i-1] 前插入 word2[j-1]
                    t3 = dp[i - 1][j - 1]; // 将 word1[i] 替换为 word2[j]
                    dp[i][j] = min(t1, min(t2, t3)) + 1;
                }
            }
        }
        return dp[len1][len2];
    }
};