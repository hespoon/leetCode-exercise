#include <stack>
#include <string>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> work;
        int ans = true;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                work.push(s[i]);
            }
            else
            {
                if (s[i] == ')')
                {
                    if (work.empty())
                    {
                        ans = false;
                        break;
                    }
                    else if (work.top() != '(')
                    {
                        ans = false;
                        break;
                    }
                    else if (work.top() == '(')
                    {
                        work.pop();
                    }
                }
                else if (s[i] == ']')
                {
                    if (work.empty())
                    {
                        ans = false;
                        break;
                    }
                    else if (work.top() != '[')
                    {
                        ans = false;
                        break;
                    }
                    else if (work.top() == '[')
                    {
                        work.pop();
                    }
                }
                else if (s[i] == '}')
                {
                    if (work.empty())
                    {
                        ans = false;
                        break;
                    }
                    else if (work.top() != '{')
                    {
                        ans = false;
                        break;
                    }
                    else if (work.top() == '{')
                    {
                        work.pop();
                    }
                }
            }
        }
        if (!work.empty())
            ans = false;
        return ans;
    }
};