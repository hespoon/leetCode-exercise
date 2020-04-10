/*
动态规划
状态定义
设状态数组 vector<vector<string>> dp，dp[i] 表示 i 对括号的所有合法组合
dp[0] 为空的 vector<string>，dp[1]={"()"}
状态转移
dp[i] 可以由向 dp[i-1] 的所有合法组合中插入一对括号得到。先插左括号，再在左括号后插右括号。
每得到一个结果都与之前的结果比较，防止重复。
由于 dp[i] 只与 dp[i-1] 有关，所以可以只用一个 vector<string> ans 来代替整个 dp 数组。
这种动规方法十分慢。。。
*/
#include <set>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        set<int> records;
        vector<string> ans;
        if (n == 0)
        {
            return ans;
        }
        else if (n == 1)
        {
            ans.push_back("()");
        }
        else
        { // n>1
            ans.push_back("()");
            for (int i = 2; i <= n; i++) // 自底向上，状态转移
            {
                records.clear();                     // 备忘录，用于防止结果重复
                vector<string> temp;                 // 用于临时记录结果
                for (int j = 0; j < ans.size(); j++) // 将第 i 个括号插入到前 i-1 个括号组成的每一个合法序列中
                {
                    for (int k = 0; k <= ans[j].length(); k++) // 先插左括号
                    {
                        string ts = ans[j];
                        int len = ts.length();
                        if (k < len)
                        {
                            ts = ts.substr(0, k) + "(" + ts.substr(k, len - k);
                        }
                        else
                        {
                            ts += "(";
                        }
                        len = ts.length();
                        for (int l = k + 1; l <= len; l++) // 在新插入的左括号右边插入右括号
                        {
                            string tts = ts;
                            if (l < len)
                            {
                                tts = tts.substr(0, l) + ")" + tts.substr(l, len - l);
                            }
                            else
                            {
                                tts += ")";
                            }
                            // 括号插入完毕，去重，并将结果放入 temp 中
                            int tInt = stringToInt(tts);
                            if (records.count(tInt) == 0)
                            { // 无重复
                                records.insert(tInt);
                                temp.push_back(tts);
                            }
                        }
                    }
                }
                ans = move(temp); // 更新 ans
            }
        }
        return ans;
    }
    int stringToInt(string s) // 将括号字符串视为二进制数字，左括号为 0，右括号为 1，将字符串转换为数字，方便去重
    {
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int t = 0;
            if (s[i] == ')')
            {
                t = 1;
            }
            ans = ans * 2 + t;
        }
        return ans;
    }
};