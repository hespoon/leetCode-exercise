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
    vector<int> postorder(Node *root)
    {
        vector<int> ans;
        vector<int> temp;
        if (!root)
            return ans;
        stack<Node *> s;
        s.push(root);
        Node *t;
        while (!s.empty())
        {
            t = s.top();
            s.pop();
            if (t)
            {
                for (int i = 0; i < t->children.size(); i++)
                {
                    s.push(t->children[i]);
                }
                temp.push_back(t->val);
            }
        }
        for (int j = temp.size() - 1; j >= 0; j--)
            ans.push_back(temp[j]);
        return ans;
    }
};