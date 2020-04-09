/*
简单的回溯法
使用深度优先搜索
统计左括号和右括号的个数，保证左括号和右括号匹配即可。当左括号与右括号相等且等于 n 时结束递归。
*/
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        DFS("(", 1, 0, n, ans);
        return ans;
    }
    void DFS(string s, int lNum, int rNum, int &n, vector<string> &ans)
    {
        if (lNum == n && rNum == n)
        {
            ans.push_back(s);
            return;
        }
        if (lNum < n)
        {
            DFS(s + '(', lNum + 1, rNum, n, ans);
        }
        if (lNum > rNum && rNum < n)
        {
            DFS(s + ')', lNum, rNum + 1, n, ans);
        }
    }
};