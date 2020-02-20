/*
使用单向链表实现的 LRU 缓存机制
*/
#include <iostream>
#include <map>
using namespace std;
struct Node // 链表节点
{
    int key, value;
    Node *next;
    Node(int _key, int _value) : key(_key), value(_value), next(NULL) {}
    Node() : next(NULL) {}
};
class LRUCache
{
public:
    int size;                   // 记录当前占用的缓存大小
    int capa;                   // 记录缓存大小
    Node *dummyHead, *tail;     // 链表的头指针和尾指针
    map<int, Node *> hashTable; // 存放 key 和指向键值为 key 的节点的前一个节点的指针，用于在 O(1) 的时间复杂度内查找和删除节点
    LRUCache(int capacity)
    {
        this->capa = capacity;        // 缓存大小
        this->size = 0;               // 当前占用的缓存大小
        this->dummyHead = new Node(); // 链表的假头节点
        this->tail = this->dummyHead; // 链表的尾节点
    }

    int get(int key)
    {
        map<int, Node *>::iterator it;
        it = hashTable.find(key);
        if (it == hashTable.end())
        { // 当前缓存中不存在目标节点
            return -1;
        }
        else
        {
            int ans = it->second->next->value;
            Node *tmp = it->second->next; // 记录当前访问节点
            if (tmp->next == NULL)
            { // 当前访问节点是尾节点，什么都不用做
                return ans;
            }
            else
            {                                              // 当前访问节点不是尾节点，将当前访问节点移动至链表尾部
                it->second->next = it->second->next->next; // 从链表中移除当前访问节点
                hashTable[tmp->next->key] = it->second;    // 更新当前访问节点的下一个节点的 hashTable 值
                this->tail->next = tmp;                    // 将当前访问节点放在链表尾部
                hashTable[key] = this->tail;               // 更新当前访问节点的 hashTable 值
                this->tail = this->tail->next;             // 更新链表尾节点
                this->tail->next = NULL;
                return ans;
            }
        }
    }

    void put(int key, int value)
    {
        if (get(key) == -1)
        { // 访问节点不存在
            if (size == capa)
            {                                                        // 缓存区占满了
                Node *tmp = this->dummyHead->next;                   // 记录要被删除的节点
                this->dummyHead->next = this->dummyHead->next->next; // 删除节点
                hashTable.erase(hashTable.find(tmp->key));           // 在 hashTable 中删除被删除节点的记录
                if (this->dummyHead->next != NULL)
                {                                                            // 如果被删除的节点不是尾节点
                    hashTable[this->dummyHead->next->key] = this->dummyHead; // 更新被删除节点的下一个节点的 hashTable 值
                }
                else
                { // 被删除节点是尾节点，则更新链表尾指针
                    this->tail = this->dummyHead;
                }
                delete tmp;                    // 释放被删除节点的内存
                tmp = new Node(key, value);    // 要插入的新节点
                hashTable[key] = this->tail;   // 在 hashTable 中记录新插入的节点
                this->tail->next = tmp;        // 将新节点放在链表尾部
                this->tail = this->tail->next; // 更新链表尾指针
            }
            else if (size < capa)
            {                                // 缓存区没满
                hashTable[key] = this->tail; // 在 hashTable 中记录新插入的节点
                size++;
                this->tail->next = new Node(key, value); // 将新节点放在链表尾部
                this->tail = this->tail->next;           // 更新链表尾指针
            }
        }
        else
        {
            // 若访问节点存在，则 get(key) 操作已经将该节点放在链表尾部了
            // 直接更新尾部节点的值即可
            this->tail->value = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */