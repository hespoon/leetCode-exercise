/*
双指针，数组，贪心
1. 盛水量取决于较短的边 
2. 两边相距越远，可能的盛水量越大
根据以上两个条件，使用两个指针，初始时分别指向数组两端。
每次将较短的边移动到下一个比它长的边的位置，同时尝试更新最大盛水量。
之所以移动较短的边，是因为如果移动较长的边，盛水量一定会因为较短边的限制而减少。
只有移动较短的边，盛水量才有可能增加。
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int ans = -1, tmp;
        while (left < right)
        {
            tmp = (right - left) * min(height[left], height[right]);
            ans = ans > tmp ? ans : tmp;
            if (height[left] < height[right])
            {
                int newL = left;
                while (newL < height.size() && height[newL] <= height[left])
                    newL++;
                left = newL;
            }
            else
            {
                int newR = right;
                while (newR >= 0 && height[newR] <= height[right])
                    newR--;
                right = newR;
            }
        }
        return ans;
    }
};