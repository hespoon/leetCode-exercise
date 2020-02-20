/*
层序遍历
*/
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
//Definition for a binary tree node.
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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> ans;
        if (root == NULL)
            return ans;
        int currLayer = 1;              // 记录当前层数
        queue<pair<TreeNode *, int>> q; // 层序遍历使用的队列，存放节点指针的节点对应的层数
        q.push(make_pair(root, 1));
        pair<TreeNode *, int> tmp;
        double layerSum = 0, layerCount = 0; // 记录一层的节点个数和节点数值和
        while (!q.empty())
        {
            tmp = q.front();
            q.pop();
            if (tmp.second == currLayer)
            {
                layerSum += tmp.first->val;
                layerCount++;
            }
            else
            {
                currLayer = tmp.second;
                double ave = layerSum / layerCount;
                ans.push_back(ave);
                layerSum = tmp.first->val;
                layerCount = 1;
            }
            if (tmp.first->left)
                q.push(make_pair(tmp.first->left, currLayer + 1));
            if (tmp.first->right)
                q.push(make_pair(tmp.first->right, currLayer + 1));
        }
        ans.push_back(layerSum / layerCount); // 最后一层的平均值
        return ans;
    }
};