/*
递归的思想
1. 反转数组的前 k 个节点，当数组节点个数不足 k 个时不反转
2. 将剩下的节点当作整体，重复第一步
*/
#include <iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL || k <= 1)
            return head; // 链表是空链表或者一个一组反转链表，都相当于不反转链表
        ListNode *nextHead = head;
        for (int i = 0; i < k; i++)
        {
            if (nextHead == NULL)
                return head; // 剩余的节点不足 k 个，则不用反转
            nextHead = nextHead->next;
        }
        ListNode *newHead = reverseList(head, nextHead); // 反转 [head,nextHead) 之间的节点。反转后，head 指向尾节点
        head->next = reverseKGroup(nextHead, k);         // k 个一组，反转剩余的链表
        return newHead;
    }
    ListNode *reverseList(ListNode *a, ListNode *b)
    { // 反转 [a,b) 之间的链表
        ListNode *dummyHead = new ListNode(0);
        ListNode *tmp;
        while (a != b)
        {
            tmp = a->next;
            a->next = dummyHead->next;
            dummyHead->next = a;
            a = tmp;
        }
        return dummyHead->next;
    }
};