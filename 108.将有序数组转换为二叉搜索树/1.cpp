/*
最蠢的解法，手写了一棵 AVL 树。
没有利用的条件：数组本身是有序的。
*/

class Solution
{
public:
    map<TreeNode *, int> nodeHeight;
    int getHeight(TreeNode *r)
    {
        if (!r)
            return 0;
        if (nodeHeight.count(r) == 1)
        {
            return nodeHeight[r];
        }
        else
        {
            nodeHeight[r] = 1;
            return 1;
        }
    }
    void updateHeight(TreeNode *r)
    {
        if (!r)
            return;
        nodeHeight[r] = max(getHeight(r->right), getHeight(r->left)) + 1;
    }
    int getBal(TreeNode *r)
    {
        return getHeight(r->left) - getHeight(r->right);
    }
    void L(TreeNode *&r)
    {
        if (!r)
            return;
        TreeNode *temp = r->right;
        r->right = r->right->left;
        temp->left = r;
        updateHeight(r);
        updateHeight(temp);
        r = temp;
    }
    void R(TreeNode *&r)
    {
        if (!r)
            return;
        TreeNode *temp = r->left;
        r->left = r->left->right;
        temp->right = r;
        updateHeight(r);
        updateHeight(temp);
        r = temp;
    }
    void Insert(TreeNode *&r, int data)
    {
        if (!r)
        {
            r = new TreeNode(data);
            return;
        }
        else if (r->val >= data)
        {
            Insert(r->left, data);
            updateHeight(r);
            int rB = getBal(r);
            int lB = getBal(r->left);
            if (rB == 2)
            {
                if (lB == 1)
                {
                    R(r);
                }
                else if (lB == -1)
                {
                    L(r->left);
                    R(r);
                }
            }
        }
        else if (r->val < data)
        {
            Insert(r->right, data);
            updateHeight(r);
            int rB = getBal(r);
            int Rb = getBal(r->right);
            if (rB == -2)
            {
                if (Rb == -1)
                {
                    L(r);
                }
                else if (Rb == 1)
                {
                    R(r->right);
                    L(r);
                }
            }
        }
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        TreeNode *root = NULL;
        for (int i = 0; i < nums.size(); i++)
        {
            Insert(root, nums[i]);
        }
        return root;
    }
};