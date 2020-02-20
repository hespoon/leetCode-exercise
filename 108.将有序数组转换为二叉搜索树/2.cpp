/*
利用数组有序这个条件，构建二叉查找树。
*/
class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.size() == 0)
            return NULL;
        return generateTree(nums, 0, nums.size() - 1);
    }
    TreeNode *generateTree(vector<int> &nums, int left, int right)
    {
        if (left > right)
            return NULL;
        int mid = (right - left) / 2 + left;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = generateTree(nums, left, mid - 1);
        root->right = generateTree(nums, mid + 1, right);
        return root;
    }
};