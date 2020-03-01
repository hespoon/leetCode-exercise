/*
动态规划
*/
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 0)
            return 0;
        int a = 1, b = 1;
        for (int i = 2; i <= n; i++)
        {
            if (i & 1)
            {
                a += b;
            }
            else
            {
                b += a;
            }
        }
        return n & 1 ? a : b;
    }
};