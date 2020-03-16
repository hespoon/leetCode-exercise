/*
二叉树线索化和莫里斯遍历
与迭代前序遍历二叉树相同
1. 令 curr 指向当前节点，temp 指向 curr 的左子树的最右节点
2. 如果 curr 没有左子树，则根据中序遍历的规则，直接将 curr 添加到结果数组中即可
3. 如果 curr 有左子树，则应当先中序遍历左子树。在此之前，应当让 curr 左子树的最右节点的右指针指向 curr。
   即令 temp->right=curr。这样做的原因是，curr 左子树中的最右节点时中序遍历序列中 curr 的前驱节点。
   也就是说，在中序遍历 curr 的左子树时，遍历到的最后一个节点是该左子树的最右节点。此时，要通过 temp->right 回到
   curr 并继续遍历 curr 的右子树。
*/
#include <vector>
#include <iostream>
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
        vector<int> ans; // 记录遍历结果的数组
        if (root == NULL)
            return ans;
        TreeNode *curr, *temp;
        curr = move(root); // move 语义，将左值 root 转换为右值
        while (curr)
        {
            temp = curr->left; // temp 指向 curr 的左子树
            if (temp)          // 如果 curr 有左子树
            {
                // 令 temp 指向 curr 左子树的最右节点
                while (temp->right != NULL && temp->right != curr)
                {
                    temp = temp->right;
                }
                // 如果 temp 的右指针已经指向 curr 了，说明此时 curr 的左子树已经处理完了，应当将 curr 加入结果数组
                if (temp->right == curr)
                {
                    ans.push_back(curr->val);
                    temp->right = NULL;
                    curr = curr->right; // 继续遍历右子树
                }
                else // 第一次遍历到左子树的最右节点，此时应生成一个回边
                {
                    temp->right = curr;
                    curr = curr->left; // 继续遍历左子树
                }
            }
            else // curr 没有左子树，直接将 curr 放入结果数组
            {
                ans.push_back(curr->val);
                curr = curr->right; // 继续遍历右子树
            }
        }
        return ans;
    }
};