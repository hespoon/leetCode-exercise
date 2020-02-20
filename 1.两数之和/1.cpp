#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        unordered_map<int, int> hashT;
        for (int i = 0; i < nums.size(); i++)
        {
            if (hashT.count(nums[i]) && nums[i] == target / 2)
            { // 重复数字
                ans.push_back(i);
                ans.push_back(hashT[nums[i]]);
                break;
            }
            else
            {
                hashT[nums[i]] = i;
            }
            if (hashT.count(target - nums[i]) && hashT[target - nums[i]] != i)
            { // 重复使用同一个数字
                ans.push_back(hashT[target - nums[i]]);
                ans.push_back(i);
            }
        }
        return ans;
    }
};