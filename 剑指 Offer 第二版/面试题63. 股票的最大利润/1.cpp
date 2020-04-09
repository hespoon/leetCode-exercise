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
        vector<int> MIN(len); // MIN[i] 记录 prices[0,i] 的最小值
        vector<int> MAX(len); // MAX[i] 记录 price[i,len-1] 的最大值
        for (int i = 0; i < len; i++)
        {
            if (i == 0)
            {
                MIN[i] = prices[i];
            }
            else
            {
                MIN[i] = min(MIN[i - 1], prices[i]);
            }
        }
        for (int i = len - 1; i >= 0; i--)
        {
            if (i == len - 1)
            {
                MAX[i] = prices[i];
            }
            else
            {
                MAX[i] = max(MAX[i + 1], prices[i]);
            }
        }
        int ans = 0;
        for (int i = 0; i < len; i++)
        {
            ans = max(ans, MAX[i] - MIN[i]);
        }
        return ans;
    }
};