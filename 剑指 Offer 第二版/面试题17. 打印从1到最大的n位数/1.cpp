/*
考察快速幂
*/
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> printNumbers(int n)
    {
        vector<int> ans;
        int end = getEnd(n);
        for (int i = 1; i < end; i++)
        {
            ans.push_back(i);
        }
        return ans;
    }
    int getEnd(int n)
    {
        if (n == 1)
            return 10;
        if (n & 1)
        {
            return getEnd(n - 1) * 10;
        }
        else
        {
            int tmp = getEnd(n >> 1);
            return tmp * tmp;
        }
    }
};