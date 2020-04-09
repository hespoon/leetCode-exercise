/*
归并排序统计数组中的逆序对的个数
在两个数组归并时，统计两个数组之间的逆序对的个数即可
*/
#include <vector>
using namespace std;
class Solution
{
public:
    int reversePairs(vector<int> &nums) // 计算 nums 中的逆序对的个数
    {
        int ans = 0;
        mergeSort(nums, 0, nums.size() - 1, ans);
        return ans;
    }
    void mergeSort(vector<int> &nums, int l, int r, int &ans) // 标准的归并排序
    {
        if (l < r) // r>l 时，将数组拆分为两部分，继续归并
        {
            int mid = (r - l) / 2 + l;
            mergeSort(nums, l, mid, ans);
            mergeSort(nums, mid + 1, r, ans);
            merge(nums, l, mid, mid + 1, r, ans);
        }
    }
    void merge(vector<int> &nums, int l1, int r1, int l2, int r2, int &ans) // 归并函数，需要修改
    {
        int len = r1 - l1 + r2 - l2 + 2; // 归并后数组的长度
        vector<int> temp(len);           // 归并后的数组
        int i = len - 1;                 // 指向 temp 的尾部，从尾部开始归并，边归并边记录逆序对的个数
        while (l1 <= r1 && l2 <= r2)
        {
            if (nums[r1] < nums[r2]) // 此时，nums[r1] 与 nums[r2] 不构成逆序对
            {
                temp[i--] = nums[r2--]; // 将较大者放入 temp 中
            }
            else if (nums[r1] == nums[r2]) // 此时，nums[r1] 可能会与 nums[r2] 之前的元素组成逆序对，所以只将 nums[r2] 放入到 temp 中
            {
                temp[i--] = nums[r2--];
            }
            else if (nums[r1] > nums[r2]) // 此时，nums[r1] 与 nums[r2] 本身和其之前的元素组成逆序对
            {
                ans += (r2 - l2 + 1);
                temp[i--] = nums[r1--];
            }
        }
        while (l1 <= r1)
        {
            temp[i--] = nums[r1--];
        }
        while (l2 <= r2)
        {
            temp[i--] = nums[r2--];
        }
        for (int j = 0; j < temp.size(); j++)
        {
            nums[l1 + j] = temp[j];
        }
    }
};