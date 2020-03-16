/*
使用栈模拟函数调用栈
令 curr 指向当前节点
如果 curr 有左子树，则 curr 压栈，且令 curr=curr->left
如果 curr 没有左子树，则直接将 curr 放入结果数组中，令 curr=curr->right
如果 curr 为 NULL，而栈不为空，则取出栈顶节点。此时意味着栈顶节点的左子树已经遍历完毕，栈顶节点直接放入结果数组。
同时令 curr=curr->right，开始处理右子树
*/
#include <vector>
#include <iostream>
#include <stack>
using namespace std;
// Definition for a binary tree node.
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans; // 存放遍历结果
        if (root == NULL)
            return ans;
        TreeNode *curr = root;                // 从根节点开始
        stack<TreeNode *> work;               // 工作栈
        while (curr != NULL || !work.empty()) // 当前节点不为空或者栈不为空
        {
            if (curr == NULL) // 如果当前节点是空接点，则从栈中弹出一个节点
            {
                if (!work.empty()) // 防御性编程。
                {
                    curr = work.top();
                    work.pop();
                }
                if (curr != NULL) // 当前节点不为空
                {
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
            else // 当前节点不是空节点
            {
                if (curr->left != NULL) // 当前节点有左子树
                {
                    work.push(curr);
                    curr = curr->left;
                }
                else // 当前节点无左子树
                {
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};