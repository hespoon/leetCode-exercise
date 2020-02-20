/*
滑动窗口+哈希表
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.length() == 0)
            return 0;
        unordered_map<char, int> subS; // 存放字母与下标的映射
        int ans = 1;
        int l = 0, r = 0; // 滑动窗口
        while (l <= r && r < s.length())
        {
            if (subS.count(s[r]) == 0)
            {
                ans = max(ans, r - l + 1);
                subS[s[r]] = r;
            }
            else
            {
                l = max(subS[s[r]] + 1, l); // 确保窗口左边界不会向左滑动，这样就不用清空哈希表了
                ans = max(ans, r - l + 1);
                subS[s[r]] = r;
            }
            r++;
        }
        return ans;
    }
};