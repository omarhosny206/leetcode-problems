// https://leetcode.com/problems/lru-cache/

class DoublyLinkedListNode
{
public:
    int key;
    int value;
    DoublyLinkedListNode *next;
    DoublyLinkedListNode *previous;

    DoublyLinkedListNode()
    {
    }

    DoublyLinkedListNode(int key, int value)
    {
        this->key = key;
        this->value = value;
    }
};

class LRUCache
{
private:
    DoublyLinkedListNode *head;
    DoublyLinkedListNode *tail;
    unordered_map<int, DoublyLinkedListNode *> node;
    int capacity;

public:
    LRUCache(int capacity)
    {
        head = new DoublyLinkedListNode();
        tail = new DoublyLinkedListNode();
        head->next = tail;
        tail->previous = head;

        this->capacity = capacity;
    }

    int get(int key)
    {
        if (node.find(key) == node.end())
            return -1;

        DoublyLinkedListNode *mostRecentlyUsedNode = node[key];

        mostRecentlyUsedNode->previous->next = mostRecentlyUsedNode->next;
        mostRecentlyUsedNode->next->previous = mostRecentlyUsedNode->previous;

        mostRecentlyUsedNode->next = head->next;
        head->next->previous = mostRecentlyUsedNode;

        mostRecentlyUsedNode->previous = head;
        head->next = mostRecentlyUsedNode;

        return mostRecentlyUsedNode->value;
    }

    void put(int key, int value)
    {
        if (node.find(key) == node.end() && node.size() == capacity)
        {
            DoublyLinkedListNode *leastRecentlyUsedNode = tail->previous;

            leastRecentlyUsedNode->previous->next = tail;
            tail->previous = leastRecentlyUsedNode->previous;

            node.erase(leastRecentlyUsedNode->key);
        }

        if (node[key] != nullptr)
        {
            DoublyLinkedListNode *mostRecentlyUsedNode = node[key];
            mostRecentlyUsedNode->value = value;

            mostRecentlyUsedNode->previous->next = mostRecentlyUsedNode->next;
            mostRecentlyUsedNode->next->previous = mostRecentlyUsedNode->previous;

            mostRecentlyUsedNode->next = head->next;
            head->next->previous = mostRecentlyUsedNode;

            mostRecentlyUsedNode->previous = head;
            head->next = mostRecentlyUsedNode;
        }

        else
        {
            DoublyLinkedListNode *mostRecentlyUsedNode = new DoublyLinkedListNode(key, value);
            node[key] = mostRecentlyUsedNode;

            mostRecentlyUsedNode->next = head->next;
            head->next->previous = mostRecentlyUsedNode;

            mostRecentlyUsedNode->previous = head;
            head->next = mostRecentlyUsedNode;

            if (node.size() == 1)
            {
                tail->previous = mostRecentlyUsedNode;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */