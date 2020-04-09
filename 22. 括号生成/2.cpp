/*
按照括号的长度自顶向下递归
合法的括号组合的样式一定是 (a)b 
令函数 generate(n) 返回 n 对括号的所有合法组合。
设 a 是 i 对括号的所有合法组合，i∈[0,n-1]，则 b 是 n-i-1 对括号的合法组合。
分别使用 generate(i) 和 gererate(n-i-1) 求出 a 和 b，然后拼接起来即可。
使用一个 unordered_map<int,vector<string>> 来记录括号对数 i 与其所有合法组合，减少递归次数，以空间换时间。
*/
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        unordered_map<int, vector<string>> records; // 备忘录，用以减少递归次数
        return generate(n, records);
    }
    vector<string> generate(int n, unordered_map<int, vector<string>> &records) // 生成 n 对括号的所有合法组合
    {
        vector<string> ans;
        if (n == 1) // 一对括号时，结果显而易见
        {
            ans.push_back("()");
            records[1] = ans;
            return ans;
        }
        else if (n == 0) // 零对括号时，结果显而易见
        {
            records[0] = ans;
            return ans;
        }
        else // 两对及两对以上的括号
        {
            for (int i = 0; i <= n - 1; i++) // 遍历 a 的括号对数
            {
                vector<string> a, b;
                if (records.count(i) == 0) // 先查备忘录，再递归
                {
                    a = move(generate(i, records)); // 使用 move 语义，加快执行速度
                    records[i] = a;
                }
                else
                {
                    a = records[i];
                }
                if (records.count(n - i - 1) == 0)
                {
                    b = move(generate(n - i - 1, records));
                    records[n - i - 1] = b;
                }
                else
                {
                    b = records[n - i - 1];
                }
                // 拼接结果
                if (a.size() == 0)
                {
                    string temp = "()";
                    if (b.size() == 0)
                    {
                        ans.push_back(temp);
                    }
                    else
                    {
                        for (int k = 0; k < b.size(); k++)
                        {
                            ans.push_back(temp + b[k]);
                        }
                    }
                }
                else
                {
                    for (int j = 0; j < a.size(); j++)
                    {
                        string temp = "(" + a[j] + ")";
                        if (b.size() == 0)
                        {
                            ans.push_back(temp);
                        }
                        else
                        {
                            for (int k = 0; k < b.size(); k++)
                            {
                                ans.push_back(temp + b[k]);
                            }
                        }
                    }
                }
            }
            return ans;
        }
    }
};