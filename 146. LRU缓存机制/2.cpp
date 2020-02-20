/*
使用双向链表实现的 LRU 缓存机制
*/
#include <iostream>
#include <map>
using namespace std;
struct Node
{
    int key, value;
    Node *next, *pre; // 双向链表
    Node(int _key, int _value) : key(_key), value(_value), next(NULL), pre(NULL) {}
    Node() : next(NULL), pre(NULL) {}
};
class LRUCache
{
public:
    int size;
    int capa;
    Node *dummyHead, *tail;
    map<int, Node *> hashTable; // 存放 key 和指向键值为 key 的节点的指针
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
        { // 当前缓存中不存在
            return -1;
        }
        else
        {
            int ans = it->second->value;
            Node *curr = it->second; // 记录当前访问节点
            if (curr->next == NULL)
            { // 当前访问节点是尾节点，什么都不用做，直接返回结果
                return ans;
            }
            else
            { // 当前访问节点不是尾节点，将当前访问节点移动至链表尾部
                // 从链表中移除当前访问节点
                removeNode(curr);
                // 将当前访问节点放在链表尾部
                this->tail->next = curr;
                curr->pre = this->tail;
                curr->next = NULL;
                // 更新链表尾节点
                this->tail = curr;
                return ans;
            }
        }
    }

    void put(int key, int value)
    {
        if (get(key) == -1)
        { // 访问节点不存在
            if (size == capa)
            {                                              // 缓存区占满了
                Node *tmp = this->dummyHead->next;         // 记录要被删除的节点
                removeNode(tmp);                           // 从链表中删除节点
                hashTable.erase(hashTable.find(tmp->key)); // 在 hashTable 中删除被删除节点的记录
                delete tmp;                                // 释放被删除节点的内存
                tmp = new Node(key, value);                // 要插入的新节点
                hashTable[key] = tmp;                      // 在 hashTable 中记录新插入的节点
                // 将新节点放在链表尾部
                this->tail->next = tmp;
                tmp->pre = this->tail;
                this->tail = this->tail->next; // 更新链表尾指针
            }
            else if (size < capa)
            {                                     // 缓存区没满
                Node *tmp = new Node(key, value); // 新插入的节点
                size++;
                // 将新节点放在链表尾部
                this->tail->next = tmp;
                tmp->pre = this->tail;
                hashTable[key] = tmp;          // 在 hashTable 中记录新插入的节点
                this->tail = this->tail->next; // 更新链表尾指针
            }
        }
        else
        {
            // 若访问节点存在，则 get(key) 操作已经将该节点放在链表尾部了
            // 直接更新尾部节点的值即可
            this->tail->value = value;
        }
    }
    void removeNode(Node *n)
    {
        if (n == NULL)
            return;
        n->pre->next = n->next; // 因为有 dummyHead 所以 n->pre 肯定是存在的
        if (n->next != NULL)
        { // n 不是尾节点
            n->next->pre = n->pre;
        }
        else
        {                        // n 是尾节点
            this->tail = n->pre; // 更新链表尾节点
        }
        n->pre = NULL;
        n->next = NULL;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */