#include <vector>
#include <cmath>
using namespace std;
class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int H)
    {
        if (piles.size() == 0)
            return 0;
        int maxPile = piles[0];
        for (int i = 1; i < piles.size(); i++)
        {
            maxPile = maxPile > piles[i] ? maxPile : piles[i];
        }
        int ans;
        if (H == piles.size())
        {
            ans = maxPile;
        }
        else if (H > piles.size())
        {
            int l = 1, r = maxPile; // 在这个范围内二分查找
            while (l < r)
            {
                int mid = (r - l) / 2 + l;
                if (isOk(mid, piles, H))
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            ans = l;
        }
        else if (H < piles.size())
        { // 吃不完
            ans = -1;
        }
        return ans;
    }
    bool isOk(int k, vector<int> &piles, int H)
    {
        int sum = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            sum += (int)ceil((double)piles[i] / (double)k);
            if (sum > H)
                return false;
        }
        return true;
    }
};