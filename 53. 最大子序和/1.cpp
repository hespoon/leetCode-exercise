/*
分治法
大问题分为三个小问题
1. 目标子数组全在左半边，下标为 (left+right)/2 的元素属于左半边
2. 目标子数组全在右半边
3. 目标子数组横跨左右两个半数组
问题 1 和 2 可以递归求解
问题 3 直接求解
时间复杂度为 O(nlogn)
*/
#include <vector>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums[0];
        int ans = getAns(nums, 0, nums.size() - 1);
        return ans;
    }
    int getAns(vector<int> &nums, int l, int r)
    {
        if (l == r)
            return nums[l];
        int mid = (r - l) / 2 + l;
        int leftMax = getAns(nums, l, mid);
        int rightMax = getAns(nums, mid + 1, r);
        int crossMidMax = findAnsCrossMid(nums, l, mid, r);
        return max(crossMidMax, max(leftMax, rightMax));
    }
    int findAnsCrossMid(vector<int> &nums, int l, int m, int r)
    {
        int leftMax = -0x7fffffff, rightMax = -0x7fffffff, sum = 0;
        for (int i = m; i >= l; i--)
        {
            sum += nums[i];
            leftMax = max(leftMax, sum);
        }
        sum = 0;
        for (int i = m + 1; i <= r; i++)
        {
            sum += nums[i];
            rightMax = max(rightMax, sum);
        }
        return leftMax + rightMax;
    }
};