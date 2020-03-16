/*
莫里斯遍历
充分利用二叉树中大量的 NULL 指针，用这些指针记录遍历到叶子节点时应当回溯到的节点。
前序遍历
1. 用 curr 指向当前节点，temp 指向 curr 左子树中的最右节点。
2. 令 temp->right=curr。记录这个信息的原因是，对以 curr 为根节点的二叉树进行前序遍历时，遍历到 curr 左子树
   的最右节点时，curr 左子树的前序遍历已经完成，接下来应该前序遍历 curr 的右子树，此时，可以通过这个指针回到 curr。
3. 对每一个节点都重复执行步骤 1 和 2
4. 在生成 temp->right=curr 这条回边时，将 curr 放入记录前序遍历序列的数组中
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
        vector<int> ans; // 存放前序遍历的结果
        if (root == NULL)
            return ans;
        TreeNode *curr, *temp;
        curr = root;
        while (curr != NULL)
        {
            temp = curr->left;
            if (temp != NULL) // curr 的左子树不为空，则先处理左子树
            {
                while (temp->right != NULL && temp->right != curr) // 寻找 curr 左子树的最右节点
                {
                    temp = temp->right;
                }
                if (temp->right == curr) // 此时说明 curr 的左子树已经处理完了，又回到了最初的起点
                {
                    temp->right = NULL; // 将添加的回边删除
                    curr = curr->right; // 处理右子树
                }
                else // curr 左子树的最右节点没有指向 curr 的回边，则添加一个回边，并将 curr 加入到结果序列中
                {
                    temp->right = curr;
                    ans.push_back(curr->val);
                    curr = curr->left;
                }
            }
            else // curr 的左子树为空，根据前序遍历的规则，将 curr 加入到结果序列中，然后处理 curr 的右子树
            {
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
    }
};