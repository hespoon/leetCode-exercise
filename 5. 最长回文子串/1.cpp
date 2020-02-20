/*
动态规划化
状态数组定义
dp[i][j] = 0 表示 s[i..j] 不是回文串
dp[i][j] = 1 表示 s[i..j] 是回文串
状态转移方程
dp[i][j] = dp[i+1][j-1], s[i]==s[j]
dp[i][j] = 0, s[i]!=s[j]
边界
dp[i][i] = 1; dp[i][i+1] = (s[i]==s[i+1])?1:0
由转移方程可知，子串的长度在不断减小，所以应以子串长度为变量来遍历子串
时间复杂度为 O(n^2)
*/
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.length() <= 1)
            return s;
        string ans = s.substr(0, 1);        // 单个字母一定是回文串
        vector<vector<int>> dp(s.length()); // 状态数组
        for (int i = 0; i < dp.size(); i++)
        { // 初始化状态数组
            dp[i].resize(s.length());
            dp[i][i] = 1;
            if (i < s.length() - 1)
            {
                if (s[i] == s[i + 1])
                {
                    dp[i][i + 1] = 1;
                    ans = s.substr(i, 2);
                }
                else
                {
                    dp[i][i + 1] = 0;
                }
            }
        }
        for (int i = 3; i <= s.length(); i++)
        { // 根据子串长度来遍历字符串
            for (int j = i - 1; j < s.length(); j++)
            {
                if (s[j] == s[j - i + 1])
                {
                    dp[j - i + 1][j] = dp[j - i + 2][j - 1];
                }
                else
                {
                    dp[j - i + 1][j] = 0;
                }
                if (i > ans.length() && dp[j - i + 1][j] == 1)
                {
                    ans = s.substr(j - i + 1, i);
                }
            }
        }
        return ans;
    }
};