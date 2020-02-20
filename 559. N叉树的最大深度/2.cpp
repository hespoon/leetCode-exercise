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
    int maxDepth(Node *root)
    {
        if (!root)
            return 0;
        stack<pair<Node *, int>> workS;
        workS.push(make_pair(root, 1));
        int ans = 0;
        pair<Node *, int> tmp;
        while (!workS.empty())
        {
            tmp = workS.top();
            workS.pop();
            ans = ans > tmp.second ? ans : tmp.second;
            for (int i = 0; i < tmp.first->children.size(); i++)
            {
                workS.push(make_pair(tmp.first->children[i], tmp.second + 1));
            }
        }
        return ans;
    }
};