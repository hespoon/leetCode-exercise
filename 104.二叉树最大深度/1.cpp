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
    int maxD;
    int maxDepth(TreeNode *root)
    {
        maxD = 0;
        return DFS(root, 0);
    }
    int DFS(TreeNode *root, int depth)
    {
        if (!root)
        {
            if (maxD < depth)
                maxD = depth;
            return maxD;
        }
        DFS(root->left, depth + 1);
        DFS(root->right, depth + 1);
        return maxD;
    }
};