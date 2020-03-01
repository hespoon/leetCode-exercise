/*
将数组 nums 中的数据减一当作索引
在 0~n 中，存在一个重复的数据和一个缺失的数据
1. 将 nums 数组中的数据减一当作索引来访问 nums 数组时，重复的数据就会导致重复访问 nums 的某个位置两次。
   因此，在通过这个新的索引 index 访问 nums 数组时，每次都将访问到的 nums[index] 变为其自身的相反数。
   如果出现访问时 nums[index] 已经是负数的请况，说明 index + 1 是重复数据。
2. 再次从 0 开始遍历 nums 数组，如果存在 nums[i] 大于零，说明在第一步中，nums[i] 未被访问到。
   即 i + 1 是缺失的那个数据。
nums 数组中的数是从 1~n 而不是 0~n-1。这是因为在 0 缺失时，0 的相反数还是零，无法判断 0 是否缺失。 
算法时间复杂度为 O(n)，空间复杂度为 O(1)。
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int dup = -1;
        int miss = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0)
            {
                dup = index + 1;
            }
            else
            {
                nums[index] *= -1;
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                miss = i + 1;
                break;
            }
        }
        vector<int> ans(2);
        ans[0] = dup;
        ans[1] = miss;
        return ans;
    }
};