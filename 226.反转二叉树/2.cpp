/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return root;
        queue<TreeNode *> qq;
        qq.push(root);
        TreeNode *tmp1, *tmp2;
        while (!qq.empty())
        {
            tmp1 = qq.front();
            qq.pop();
            if (tmp1)
            {
                tmp2 = tmp1->right;
                tmp1->right = tmp1->left;
                tmp1->left = tmp2;
                qq.push(tmp1->left);
                qq.push(tmp1->right);
            }
        }
        return root;
    }
};