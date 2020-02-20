/*
递归，利用二叉搜索树的特性
若 p,q 都在根的子树中，则在子树中搜索，否则，根就是目标节点
*/

#include <iostream>
using namespace std;
//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;
        int min = p->val <= q->val ? p->val : q->val;
        int max = p->val > q->val ? p->val : q->val;
        return DFS(root, min, max);
    }
    TreeNode *DFS(TreeNode *root, int min, int max)
    {
        if (root == NULL)
            return NULL;
        if (root->val < min)
        {
            return DFS(root->right, min, max);
        }
        else if (root->val >= min && root->val <= max)
        {
            return root;
        }
        else if (root->val > max)
        {
            return DFS(root->left, min, max);
        }
        return NULL;
    }
};