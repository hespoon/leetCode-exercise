/*
时间复杂度为 O(n)，空间复杂度为 O(1)
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() <= 1)
            return 0;
        int len = prices.size();
        int ans = 0;
        int MIN; // MIN 记录 prices[0,i] 的最小值
        for (int i = 0; i < len; i++)
        {
            MIN = min(MIN, prices[i]);
            ans = max(ans, prices[i] - MIN); // 以 prices[i] 的价格卖出股票可获得最大利润为 prices[i]-MIN
        }
        return ans;
    }
};