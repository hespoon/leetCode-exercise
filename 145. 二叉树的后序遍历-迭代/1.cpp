/*
使用一个栈模拟函数递归调用
使用一个 set 记录节点是否被访问过
*/
#include <vector>
#include <stack>
#include <unordered_set>
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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans; // 结果数组
        if (root == NULL)
        {
            return ans;
        }
        stack<TreeNode *> work;        // 工作栈
        unordered_set<TreeNode *> vis; // 标记 map
        TreeNode *curr;
        work.push(root);
        while (!work.empty()) // 保证栈不为空
        {
            curr = work.top();
            work.pop();
            if (curr->left == NULL && curr->right == NULL) // 当前节点是叶子节点
            {
                ans.push_back(curr->val);
                vis.insert(curr);
            }
            else if (curr->left != NULL && vis.count(curr->left) == 0) // 当前节点有左子树 && 左子树没有被访问
            {
                work.push(curr);
                work.push(curr->left);
            }
            else if (curr->right != NULL && vis.count(curr->right) == 0) // 当前节点有右子树 && 右子树没有被访问
            {
                work.push(curr);
                work.push(curr->right);
            }
            else // 当前节点有左子树和右子树，但是两者都被访问了
            {
                ans.push_back(curr->val);
                vis.insert(curr);
            }
        }
        return ans;
    }
};