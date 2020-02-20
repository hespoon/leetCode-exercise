/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
    {
        if (!t1)
            return t2;
        if (!t2)
            return t1;
        stack<TreeNode *> st1, st2;
        st1.push(t1);
        st2.push(t2);
        TreeNode *tmp1, *tmp2;
        while (!st1.empty() && !st2.empty())
        {
            tmp1 = st1.top();
            tmp2 = st2.top();
            st1.pop();
            st2.pop();
            int temp = tmp1->val;
            tmp1->val += tmp2->val;
            tmp2->val += temp;

            if (!tmp1->left && tmp2->left)
            {
                tmp1->left = new TreeNode(0);
            }
            else if (tmp1->left && !tmp2->left)
            {
                tmp2->left = new TreeNode(0);
            }
            if (tmp1->left && tmp2->left)
            {
                st1.push(tmp1->left);
                st2.push(tmp2->left);
            }

            if (!tmp1->right && tmp2->right)
            {
                tmp1->right = new TreeNode(0);
            }
            else if (tmp1->right && !tmp2->right)
            {
                tmp2->right = new TreeNode(0);
            }
            if (tmp1->right && tmp2->right)
            {
                st1.push(tmp1->right);
                st2.push(tmp2->right);
            }
        }
        return st1.empty() ? t2 : t1;
    }
};