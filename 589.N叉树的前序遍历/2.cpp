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
    vector<int> preorder(Node *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        stack<Node *> s;
        s.push(root);
        Node *t;
        while (!s.empty())
        {
            t = s.top();
            s.pop();
            ans.push_back(t->val);
            for (int i = t->children.size() - 1; i >= 0; i--)
                s.push(t->children[i]);
        }
        return ans;
    }
};