#include <iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
求链表中间节点和切分链表要分开操作
*/
class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (!head)
            return NULL;
        ListNode *mid = getMid(head);
        TreeNode *root = new TreeNode(mid->val);
        head = cutList(head, mid);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        return root;
    }
    ListNode *getMid(ListNode *head)
    {
        ListNode *f, *l;
        f = l = head;
        while (f && f->next)
        {
            l = l->next;
            f = f->next->next;
        }
        return l;
    }
    ListNode *cutList(ListNode *head, ListNode *mid)
    {
        if (head == mid)
            return NULL;
        else
        {
            ListNode *t = head;
            while (t && t->next != mid)
                t = t->next;
            t->next = NULL;
            return head;
        }
    }
};