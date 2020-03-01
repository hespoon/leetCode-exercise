/*
神奇的位运算
nums 中的数据的取值是 1~nums.size() 并且有一个数据出现了两次，同时有一个数据没有出现
将 nums[0]~nums[nums.size()-1] 与 1~nums.size() 做异或运算，可以得到重复出现的数据与缺失的数据的异或值 Xor
该异或值的特点是，重复出现的数据与缺失数据在相同的位取 0，不同的位取 1
对 Xor 做 lowbit 运算，即 Xor & (-Xor) 得到 Xor 二进制表示的最右边的第一个 1 与之后的 0 组成的数 lowbit
可以通过这个 lowbit 将重复出现的数据和缺失数据分开
通过 lowbit 将 nums[0]~nums[nums.size()-1] 分为两部分 A 和 B，同时将 1~nums.size() 分为两部分 a 和 b。
对应部分做异或运算，得到的两个值，一个是缺失数据，一个是重复出现的数据
再遍历一遍 nums 数组，选出重复出现的数据，另一个就是缺失的数据
时间复杂度为 O(n)，空间复杂度为 O(1)
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
        int Xor = 0, Xor1 = 0, Xor0 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            Xor ^= i + 1;
            Xor ^= nums[i];
        }
        int lowbit = Xor & (-Xor); // 获得 Xor 二进制的最右边的第一个 1
        for (int i = 0; i < nums.size(); i++)
        {
            if (((i + 1) & lowbit) == 0)
            { // i 在该位置上是 0
                Xor0 ^= i + 1;
            }
            else
            {
                Xor1 ^= i + 1;
            }
            if ((nums[i] & lowbit) == 0)
            {
                Xor0 ^= nums[i];
            }
            else
            {
                Xor1 ^= nums[i];
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (Xor0 == nums[i])
            {
                dup = Xor0;
                miss = Xor1;
                break;
            }
            else if (Xor1 == nums[i])
            {
                dup = Xor1;
                miss = Xor0;
                break;
            }
        }
        vector<int> ans(2);
        ans[0] = dup;
        ans[1] = miss;
        return ans;
    }
};