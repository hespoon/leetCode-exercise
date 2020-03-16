/*
此题不可以使用 long long 
使用数学方法反转数字，反转时判断是否溢出
*/
#include <iostream>
using namespace std;
class Solution
{
public:
    int reverse(int x)
    { // 此题不可以使用 long long
        int temp;
        int ans = 0;
        while (x)
        {
            temp = x % 10;
            x /= 10;
            if (ans > 0 && (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && temp > 7)))
                return 0;
            if (ans < 0 && (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && temp < -8)))
                return 0;
            ans = ans * 10 + temp;
        }
        return ans;
    }
};