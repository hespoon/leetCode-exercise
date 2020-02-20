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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> ans; // 存放结果
        if (root == NULL)
            return ans;
        vector<int> tmv;                // 存放一层的遍历结果
        stack<vector<int>> workS;       // 将层序遍历结果正序压栈，然后再出栈得到倒序
        int currLayer = 1;              // 分层，记录当前层数
        queue<pair<TreeNode *, int>> q; // 层序遍历使用的队列，队中元素记录节点指针和节点对应的层数
        q.push(make_pair(root, 1));
        while (!q.empty())
        {
            pair<TreeNode *, int> tmp = q.front();
            q.pop();
            if (tmp.second == currLayer)
            {
                tmv.push_back(tmp.first->val);
            }
            else
            {
                workS.push(tmv);
                tmv.clear();
                currLayer = tmp.second;
                tmv.push_back(tmp.first->val);
            }
            if (tmp.first->left)
                q.push(make_pair(tmp.first->left, tmp.second + 1));
            if (tmp.first->right)
                q.push(make_pair(tmp.first->right, tmp.second + 1));
        }
        workS.push(tmv); // 把最后一层的节点压入栈中
        while (!workS.empty())
        {
            ans.push_back(workS.top());
            workS.pop();
        }
        return ans;
    }
};