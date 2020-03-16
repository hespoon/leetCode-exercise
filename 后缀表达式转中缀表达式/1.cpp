#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <sstream>
using namespace std;
struct Node
{
    char val;
    Node *left, *right;
    Node() : left(NULL), right(NULL) {}
    Node(char _val) : val(_val), left(NULL), right(NULL) {}
};
Node *suffixExpToBinaryTree(string); // 后缀表达式转二叉树，成功时返回指向二叉树根节点的指针，失败时返回 NULL
string binaryTreeToInfixExp(Node *); // 二叉树转中缀表达式
Node *getStackTop(stack<Node *> &);  // 获取栈顶元素并将栈顶出栈
void initMap(map<char, int> &);
map<char, int> op; // 存放操作符优先级的表
int main()
{
    string suffixExp, infixExp;
    cin >> suffixExp;
    Node *root = suffixExpToBinaryTree(suffixExp);
    if (root == NULL)
    {
        cout << "error suffix expression\n";
    }
    else
    {
        initMap(op);
        infixExp = binaryTreeToInfixExp(root);
        cout << infixExp;
    }
    return 0;
}
void initMap(map<char, int> &op)
{
    op.insert(make_pair('+', 1));
    op.insert(make_pair('-', 1));
    op.insert(make_pair('*', 2));
    op.insert(make_pair('/', 2));
    for (int i = '0'; i <= '9'; i++) // 存储字符的优先级
    {
        op[i] = 3;
    }
}
Node *suffixExpToBinaryTree(string suf)
{
    stack<Node *> work;
    Node *tmp, *l, *r;
    for (int i = 0; i < suf.length(); i++)
    {
        tmp = new Node(suf[i]);
        if (suf[i] >= '0' && suf[i] <= '9')
        { // 数字
            work.push(tmp);
        }
        else
        { // 操作符，且都是二元操作符
            r = getStackTop(work);
            l = getStackTop(work);
            if (r == NULL || l == NULL)
            { // 后缀表达式不正确
                return NULL;
            }
            else
            {
                tmp->right = r;
                tmp->left = l;
                work.push(tmp);
            }
        }
    }
    if (work.size() == 1)
    {
        return work.top();
    }
    else
    { // 后缀表达式不正确
        return NULL;
    }
}
string binaryTreeToInfixExp(Node *root)
{
    stringstream ss;  // 字符转字符串
    if (root == NULL) // 空节点
        return "";
    if (root->val >= '0' && root->val <= '9') // 数字节点
    {
        ss << root->val;
        return ss.str();
    }
    string ans, leftCh, rightCh;
    int rootPriority = op[root->val];
    if (root->left)
    {
        int leftPriority = op[root->left->val];
        leftCh = binaryTreeToInfixExp(root->left);
        if (leftPriority < rootPriority)
        {
            ans += "(" + leftCh + ")";
        }
        else
        {
            ans += leftCh;
        }
    }
    ss << root->val;
    ans += ss.str();
    if (root->right)
    {
        int rightPriority = op[root->right->val];
        rightCh = binaryTreeToInfixExp(root->right);
        if (rightPriority < rootPriority)
        {
            ans += "(" + rightCh + ")";
        }
        else
        {
            ans += rightCh;
        }
    }
    return ans;
}
Node *getStackTop(stack<Node *> &s)
{
    if (s.empty())
    {
        return NULL;
    }
    else
    {
        Node *ans = s.top();
        s.pop();
        return ans;
    }
}