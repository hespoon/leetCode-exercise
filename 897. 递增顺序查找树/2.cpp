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
        vector<int> data;
        inOrder(root, data);
        return createTree(data);
    }
    void inOrder(TreeNode *root, vector<int> &data)
    {
        if (root == NULL)
            return;
        inOrder(root->left, data);
        data.push_back(root->val);
        inOrder(root->right, data);
    }
    TreeNode *createTree(vector<int> data)
    {
        TreeNode *root = new TreeNode(data[0]);
        TreeNode *tmp = root;
        for (int i = 1; i < data.size(); i++)
        {
            tmp->right = new TreeNode(data[i]);
            tmp = tmp->right;
        }
        return root;
    }
};