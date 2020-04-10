/*
先将字符串中的单词全部压栈，然后出栈，自然就实现了逐个反转单词
使用 stringstream 按空格分割源字符串。
注意：连续的分割符会导致 stringstream 分割到空串！！
*/
#include <sstream>
#include <stack>
#include <string>
using namespace std;
class Solution
{
public:
    string reverseWords(string s)
    {
        string ans;
        stack<string> work;
        stringstream ss(s);
        while (getline(ss, s, ' ')) // 连续的空格会使 s 为空串
        {
            work.push(s);
        }
        bool first = true;
        while (!work.empty())
        {
            if (work.top() != "")
            {
                if (first)
                {
                    first = false;
                }
                else
                {
                    ans += ' ';
                }
                ans += work.top();
            }
            work.pop();
        }
        return ans;
    }
};