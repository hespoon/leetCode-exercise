/*
使用一个栈来模拟递归调用时的函数压栈
压栈时先压右子树，再压左子树，使得树的遍历顺序为 top → down，left → right
*/
#include <stack>
#include <vector>
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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans; // 存放遍历结果
        if (root == NULL)
            return ans;
        stack<TreeNode *> work; // 模拟函数调用栈
        work.push(root);        // 根节点入栈
        TreeNode *curr;         // 指向当前节点
        while (!work.empty())   // 保证栈非空
        {
            curr = work.top(); // 获取当前节点
            work.pop();        // 弹栈
            if (curr != NULL)  // 当前节点非空
            {
                ans.push_back(curr->val); // 记录当前节点的值
                work.push(curr->right);   // 先将右子树压栈
                work.push(curr->left);    // 再将左子树压栈，确保下次访问时先访问左子树
            }
        }
        return ans;
    }
};