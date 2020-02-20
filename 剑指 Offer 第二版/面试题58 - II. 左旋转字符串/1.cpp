#include <string>
using namespace std;
class Solution
{
public:
    string reverseLeftWords(string s, int n)
    {
        Rev(s, 0, n - 1);
        Rev(s, n, s.length() - 1);
        Rev(s, 0, s.length() - 1);
        return s;
    }
    void Rev(string &s, int l, int r)
    {
        while (l < r)
        {
            char t = s[l];
            s[l] = s[r];
            s[r] = t;
            l++;
            r--;
        }
    }
};