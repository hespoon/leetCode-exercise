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
    TreeNode *increasingBST(TreeNode *root)
    {
        if (root == NULL)
            return NULL;
        TreeNode *rightMost;
        return inOrder(root, rightMost);
    }
    TreeNode *inOrder(TreeNode *root, TreeNode *&rightMost)
    {
        if (root->left == NULL && root->right == NULL)
        { // 叶子节点
            rightMost = root;
            return root;
        }
        rightMost = root;
        while (rightMost && rightMost->right)
        {
            rightMost = rightMost->right;
        }
        TreeNode *leftChilRightMost, *rightChilRightMost, *newRoot;
        if (root->left)
        { // 左子树存在
            newRoot = inOrder(root->left, leftChilRightMost);
            leftChilRightMost->right = root;
            root->left = NULL;
        }
        else
        { // 左子树不存在
            newRoot = root;
        }
        if (root->right)
            root->right = inOrder(root->right, rightChilRightMost);
        return newRoot;
    }
};