/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution
{
public:
    int ans = 0; // 最大深度
    int maxDepth(Node *root)
    {
        if (!root)
            return 0;
        DFS(root, 1);
        return ans;
    }
    void DFS(Node *root, int deep)
    {
        if (deep > ans)
            ans = deep;
        if (!root)
            return;
        for (int i = 0; i < root->children.size(); i++)
        {
            DFS(root->children[i], deep + 1);
        }
    }
};