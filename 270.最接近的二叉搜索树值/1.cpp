/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 利用二叉搜索树的特殊性质，使用二分查找
class Solution
{
public:
    int ans;
    double diff;
    int closestValue(TreeNode *root, double target)
    {
        ans = root->val;
        diff = fabs(ans - target);
        closest(root, target);
        return ans;
    }
    void closest(TreeNode *root, double target)
    {
        if (!root)
            return;
        double t = fabs(target - root->val);
        if (t < diff)
        {
            ans = root->val;
            diff = t;
        }
        root->val > target ? closest(root->left, target) : closest(root->right, target);
    }
};