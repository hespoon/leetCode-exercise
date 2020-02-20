/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* 
中序遍历，更改指针指向。
记录前一个遍历到的节点，将当前节点设为前一节点的右子节点，同时更新前一节点。
*/
class Solution
{
public:
    TreeNode *increasingBST(TreeNode *root)
    {
        if (root == NULL)
            return NULL;
        TreeNode *pre = new TreeNode(0); // 类似链表的虚假头结点
        TreeNode *ans = pre;
        inOrder(root, pre);
        return ans->right;
    }
    void inOrder(TreeNode *root, TreeNode *&pre)
    {
        if (root == NULL)
            return;
        inOrder(root->left, pre);
        pre->right = root;
        root->left = NULL;
        pre = root;
        inOrder(root->right, pre);
    }
};