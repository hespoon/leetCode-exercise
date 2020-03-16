/*
二分查找
*/
#include <algorithm>
using namespace std;
class Solution
{
public:
    int fun(int m, int n, int num)
    { // 统计 m * n 大小的乘法表中，值小于等于 num 的元素的个数
        int count = 0;
        for (int i = 1; i <= m; i++)
        {
            count += min(num / i, n); // 统计第 i 行值小于等于 num 的元素的个数
        }
        return count;
    }
    int findKthNumber(int m, int n, int k)
    {
        if (k == 1)
            return 1;
        if (k == m * n)
            return m * n;
        int l = 1, r = m * n; // 将值作为二分的边界
        while (l < r)
        {
            int mid = (r - l) / 2 + l;
            int temp = fun(m, n, mid); // 查看 m * n 的乘法表中，值小于等于 mid 的元素的个数
            if (temp >= k)
            { // temp = k 时，mid 的值不一定是乘法表中有的；由于乘法表中存在多个重复的值，所以 temp > k 时，mid 可能是最终答案
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};