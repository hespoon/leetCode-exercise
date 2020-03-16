/*
使用一个栈模仿函数递归调用
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
        vector<int> ans; // 结果数组
        if (root == NULL)
            return ans;
        TreeNode *curr = root;
        stack<TreeNode *> work; // 栈，模拟函数调用
        while (!work.empty())   // 栈不为空
        {
            while (curr != NULL) // 一路向左下，直到叶子节点
            {
                work.push(curr);
                curr = curr->left;
            }
            curr = work.top();        // 获取栈顶
            work.pop();               // 出栈
            ans.push_back(curr->val); // 将当前节点的值放入结果数组
            curr = curr->right;       // 开始处理右子树
        }
        return ans;
    }
};