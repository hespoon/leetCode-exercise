/*
使用自带的 reverse 函数反转字符串
进行两次反转，第一次反转整个字符串，第二次使用滑动窗口取出字符串的单词再反转
*/
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string reverseWords(string s)
    {
        string ans;
        reverse(s.begin(), s.end());
        int l = 0, r = 0, len = s.length();
        bool first = true;
        while (r < len)
        {
            string t;
            l = r;
            while (l < len && s[l] == ' ')
                l++;
            r = l;
            while (r < len && s[r] != ' ')
            {
                t += s[r++];
            }
            if (t.length() > 0)
            {
                reverse(t.begin(), t.end());
                if (first)
                {
                    first = false;
                }
                else
                {
                    t = ' ' + t;
                }
                ans += t;
            }
        }
        return ans;
    }
};