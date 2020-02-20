/*
动态规划：dp[i] 表示以字符 s[i] 结尾的，无重复字符的最长子串的长度
dp[i] = dp[i-1] + 1 当 s[i] 与 s[0..i-1] 无重复字母。
利用哈希表判断字母是否重复。
当有重复字母时，利用哈希表，记录重复字母的下标，计算符合条件的子串的长度。
明显，在有重复字母存在时，dp[i] 与 dp[i-1] 之间联系不大
*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.length() == 0)
            return 0;
        unordered_map<char, int> subS;
        vector<int> dp(s.length());
        dp[0] = 1;
        subS[s[0]] = 0;
        int ans = 1;
        for (int i = 1; i < s.length(); i++)
        {
            if (subS.count(s[i]) == 0)
            {
                dp[i] = dp[i - 1] + 1;
                subS[s[i]] = i;
            }
            else
            {
                int left = subS[s[i]];
                dp[i] = i - left;
                subS.clear();
                for (int j = left; j <= i; j++)
                {
                    subS[s[j]] = j;
                }
            }
            ans = ans > dp[i] ? ans : dp[i];
        }
        return ans;
    }
};