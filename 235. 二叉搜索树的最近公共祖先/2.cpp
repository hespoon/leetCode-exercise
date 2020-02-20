/*
由于二叉搜索树的特性，在查找最小公共祖先时是不用回溯的，只要找到分界点即可，因此可以使用迭代实现。
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
        TreeNode *tmp = root;
        while (tmp) // 寻找分界点
        {
            if (tmp->val < min)
            {
                tmp = tmp->right;
                continue;
            }
            else if (tmp->val > max)
            {
                tmp = tmp->left;
                continue;
            }
            else
            {
                break;
            }
        }
        return tmp;
    }
};