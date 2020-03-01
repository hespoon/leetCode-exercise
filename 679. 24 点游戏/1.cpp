/*
深度优先搜索
可用的操作符中包含左右括号，处理起来比较麻烦，可以使用后缀表达式来计算，这样就不用考虑括号了
根据四个操作数和四个操作符，发现可以构建五种后缀表达式
ab+c+d+
ab+cd++
abc++d+
abc+d++
abcd+++
a、b、c、d 代表数字，+ 代表运算符
用二叉树表示这五种后缀表达式，二叉树只有五个叶子节点，一条从根节点到叶子节点的路径表示一种后缀表达式，共五条路径。
用深度优先搜索遍历这棵二叉树，遍历到叶子节点时，便获得了一个后缀表达式，计算该后缀表达式的值。
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;
struct node
{
    bool isNum;
    node *left, *right;
    node(bool _isNum) : isNum(_isNum), left(NULL), right(NULL) {}
    node() : isNum(true), left(NULL), right(NULL) {}
};
class Solution
{
public:
    // + = 10; - = 11; * = 12; / = 13; 操作符映射为数字
    bool judgePoint24(vector<int> &nums)
    {
        bool ans = false;
        node *root = createTree(); // 构建符合条件的二叉树
        vector<double> suffixExp;
        bool used[4] = {false, false, false, false};
        DFS(root, used, nums, suffixExp, ans);
        return ans;
    }
    void DFS(node *root, bool used[], vector<int> &nums, vector<double> &sufExp, bool &ans) // 遍历二叉树，生成后缀表达式
    {
        if (ans)
            return; // 得到 24 了
        if (root == NULL)
        {
            double tmp = calculate(sufExp);
            if (sufExp.size() == 7 && fabs(tmp - 24) <= 1e-6)
            {
                ans = true; // 计算后缀表达式
                for (int i = 0; i < sufExp.size(); i++)
                {
                    cout << sufExp[i] << "  ";
                }
            }
            return;
        }
        if (root->isNum)
        {
            for (int i = 0; i < 4; i++)
            { // 从 4 张牌中选一张没有使用的
                if (!used[i])
                {
                    used[i] = true;
                    sufExp.push_back((double)nums[i]);
                    DFS(root->left, used, nums, sufExp, ans);
                    DFS(root->right, used, nums, sufExp, ans);
                    used[i] = false;
                    sufExp.pop_back();
                }
            }
        }
        else
        {
            for (int i = 10; i <= 13; i++)
            { // 四种操作符分别使用一次
                sufExp.push_back((double)i);
                DFS(root->left, used, nums, sufExp, ans);
                DFS(root->right, used, nums, sufExp, ans);
                sufExp.pop_back();
            }
        }
    }
    double calculate(vector<double> &sufExp) // 计算后缀表达式
    {
        bool error = false; // 标记后缀表达式是否正确
        stack<double> tmp;
        for (int i = 0; i < sufExp.size(); i++)
        {
            int currNum = sufExp[i];
            if (currNum >= 0 && currNum <= 9)
            { // 操作数，直接压栈
                tmp.push(currNum);
            }
            else
            { // 操作符，弹栈计算
                double se, fi;
                if (!tmp.empty())
                {
                    se = tmp.top();
                    tmp.pop();
                }
                else
                {
                    error = true;
                    break;
                }
                if (!tmp.empty())
                {
                    fi = tmp.top();
                    tmp.pop();
                }
                else
                {
                    error = true;
                    break;
                }
                if (currNum == 10)
                { // 加法
                    tmp.push(fi + se);
                }
                if (currNum == 11)
                { // 减法
                    tmp.push(fi - se);
                }
                if (currNum == 12)
                { // 乘法
                    tmp.push(fi * se);
                }
                if (currNum == 13)
                { // 除法
                    if (se == 0)
                    {
                        error = true;
                        break;
                    }
                    else
                        tmp.push(fi / se);
                }
            }
        }
        if (!error && tmp.size() == 1)
        {
            return tmp.top();
        }
        else
        {
            return -1;
        }
    }
    node *createTree() // 手动构建代表后缀表达式的二叉树
    {
        node *tmp, *ttmp;
        node *root = new node();
        root->right = new node();
        tmp = root->right;
        tmp->right = new node();
        tmp->left = new node(false);
        tmp = tmp->left;
        tmp->right = new node();
        tmp = tmp->right;
        tmp->right = new node();
        tmp->left = new node(false);
        ttmp = tmp->left;
        tmp = tmp->right;
        for (int i = 0; i < 2; i++)
        {
            tmp->right = new node(false);
            tmp = tmp->right;
            if (i == 0)
                ttmp->right = new node();
            else
                ttmp->right = new node(false);
            ttmp = ttmp->right;
        }
        tmp = root->right->right;
        tmp->right = new node(false);
        tmp = tmp->right;
        tmp->right = new node();
        tmp->left = new node(false);
        ttmp = tmp->left;
        tmp = tmp->right;
        for (int i = 0; i < 2; i++)
        {
            tmp->right = new node(false);
            tmp = tmp->right;
            if (i == 0)
                ttmp->right = new node();
            else
                ttmp->right = new node(false);
            ttmp = ttmp->right;
        }
        tmp = root->right->right;
        tmp->left = new node();
        tmp = tmp->left;
        for (int i = 0; i < 3; i++)
        {
            tmp->right = new node(false);
            tmp = tmp->right;
        }
        return root;
    }
    void printTree(node *root)
    {
        queue<pair<node *, int>> q;
        int currLayer = 1;
        q.push(make_pair(root, 1));
        while (!q.empty())
        {
            pair<node *, int> tmp = q.front();
            q.pop();
            if (tmp.second != currLayer)
            {
                cout << endl;
                currLayer = tmp.second;
            }
            if (tmp.first->isNum)
            {
                cout << "n ";
            }
            else
            {
                cout << "o ";
            }
            if (tmp.first->left)
                q.push(make_pair(tmp.first->left, currLayer + 1));
            if (tmp.first->right)
                q.push(make_pair(tmp.first->right, currLayer + 1));
        }
    }
};