/*
1. 计算链表总长度 len
2. 计算 len/k 向下取整，得到 k 个一组共几组
3. 使用头插法反转链表，每翻转 k 个，更新一次头的位置
4. 将剩余的节点接在新链表尾部
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
        if (k <= 1)
            return head;
        ListNode *dummyHead = new ListNode(0);
        ListNode *tmp, *tmpHead, *work;
        int listLength = 0;
        tmpHead = head;
        while (tmpHead != NULL)
        { // 计算链表长度
            listLength++;
            tmpHead = tmpHead->next;
        }
        int turns = listLength / k; // 计算以 k 个节点一组，共有多少组
        work = head;
        tmpHead = dummyHead;
        for (int i = 0; i < turns; i++)
        { // k 个一组，反转 turns 次
            for (int j = 0; j < k; j++)
            { // 头插法反转
                tmp = work->next;
                work->next = tmpHead->next;
                tmpHead->next = work;
                work = tmp;
            }
            for (int j = 0; j < k; j++)
            { // 更新临时链表头
                tmpHead = tmpHead->next;
            }
        }
        tmpHead->next = work; // 将剩余的节点接在新链表的尾部
        return dummyHead->next;
    }
};