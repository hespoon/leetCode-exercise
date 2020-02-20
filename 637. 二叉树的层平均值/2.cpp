/*
深度优先搜索
要记录当前节点的层数
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
        vector<double> sum; // 记录每层节点的数值和
        vector<int> count;  // 记录每层节点的个数
        DFS(root, sum, count, 0);
        vector<double> ans;
        for (int i = 0; i < sum.size(); i++)
        {
            ans.push_back(sum[i] / count[i]);
        }
        return ans;
    }
    void DFS(TreeNode *root, vector<double> &sum, vector<int> &count, int layer)
    {
        if (root == NULL)
            return;
        if (sum.size() <= layer)
        {
            sum.push_back(root->val);
            count.push_back(1);
        }
        else
        {
            sum[layer] += root->val;
            count[layer]++;
        }
        DFS(root->left, sum, count, layer + 1);
        DFS(root->right, sum, count, layer + 1);
    }
};