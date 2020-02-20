/*
递归
树的定义是递归定义，则递归操作时按照树的定义来
*/
//Definition for a binary tree node.
#include <iostream>
using namespace std;
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
    TreeNode *trimBST(TreeNode *root, int L, int R)
    {
        if (root == NULL)
            return NULL;
        TreeNode *newRoot;
        if (root->val >= L && root->val <= R)
        {
            newRoot = root;
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
        }
        else if (root->val < L)
        {
            newRoot = trimBST(root->right, L, R);
        }
        else if (root->val > R)
        {
            newRoot = trimBST(root->left, L, R);
        }
        return newRoot;
    }
};