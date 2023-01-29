// https://leetcode.com/problems/lfu-cache/

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

class Cache
{
public:
    int key;
    int value;
    DoublyLinkedListNode *head;
    DoublyLinkedListNode *tail;

    Cache()
    {
        head = new DoublyLinkedListNode();
        tail = new DoublyLinkedListNode();

        head->next = tail;
        tail->previous = head;
    }
};

class LFUCache
{
    map<int, Cache *> cache;
    unordered_map<int, DoublyLinkedListNode *> node;
    unordered_map<int, int> freq;
    int capacity;

public:
    LFUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (node.find(key) == node.end())
            return -1;

        freq[key]++;

        if (cache.find(freq[key]) == cache.end())
            cache[freq[key]] = new Cache();

        Cache *currentCache = cache[freq[key]];
        DoublyLinkedListNode *mostRecentlyUsedNode = node[key];

        if (freq[key] == 1)
        {
            mostRecentlyUsedNode->next = currentCache->head->next;
            currentCache->head->next->previous = mostRecentlyUsedNode;

            mostRecentlyUsedNode->previous = currentCache->head;
            currentCache->head->next = mostRecentlyUsedNode;
        }

        else
        {
            mostRecentlyUsedNode->previous->next = mostRecentlyUsedNode->next;
            mostRecentlyUsedNode->next->previous = mostRecentlyUsedNode->previous;

            mostRecentlyUsedNode->next = currentCache->head->next;
            currentCache->head->next->previous = mostRecentlyUsedNode;

            mostRecentlyUsedNode->previous = currentCache->head;
            currentCache->head->next = mostRecentlyUsedNode;
        }

        if (mostRecentlyUsedNode->next == currentCache->tail)
            currentCache->tail->previous = mostRecentlyUsedNode;

        if (freq[key] > 1)
        {
            Cache *previousCache = cache[freq[key] - 1];

            if (previousCache->head->next == previousCache->tail)
                cache.erase(freq[key] - 1);
        }

        return node[key]->value;
    }

    void put(int key, int value)
    {
        if (capacity == 0)
            return;

        if (node.find(key) == node.end() && node.size() == capacity)
        {
            Cache *leastFrequentlyUsedCache = cache[cache.begin()->first];
            DoublyLinkedListNode *leastRecentlyUsedNode = leastFrequentlyUsedCache->tail->previous;

            leastRecentlyUsedNode->previous->next = leastFrequentlyUsedCache->tail;
            leastFrequentlyUsedCache->tail->previous = leastRecentlyUsedNode->previous;

            node.erase(leastRecentlyUsedNode->key);
            freq.erase(leastRecentlyUsedNode->key);

            if (leastFrequentlyUsedCache->head->next == leastFrequentlyUsedCache->tail)
                cache.erase(cache.begin()->first);
        }

        if (node.find(key) == node.end())
            node[key] = new DoublyLinkedListNode(key, value);

        else
            node[key]->value = value;

        freq[key]++;

        if (cache.find(freq[key]) == cache.end())
            cache[freq[key]] = new Cache();

        Cache *currentCache = cache[freq[key]];
        DoublyLinkedListNode *mostRecentlyUsedNode = node[key];

        if (freq[key] == 1)
        {
            mostRecentlyUsedNode->next = currentCache->head->next;
            currentCache->head->next->previous = mostRecentlyUsedNode;

            mostRecentlyUsedNode->previous = currentCache->head;
            currentCache->head->next = mostRecentlyUsedNode;
        }

        else
        {
            mostRecentlyUsedNode->previous->next = mostRecentlyUsedNode->next;
            mostRecentlyUsedNode->next->previous = mostRecentlyUsedNode->previous;

            mostRecentlyUsedNode->next = currentCache->head->next;
            currentCache->head->next->previous = mostRecentlyUsedNode;

            mostRecentlyUsedNode->previous = currentCache->head;
            currentCache->head->next = mostRecentlyUsedNode;
        }

        if (mostRecentlyUsedNode->next == currentCache->tail)
            currentCache->tail->previous = mostRecentlyUsedNode;

        if (freq[key] > 1)
        {
            Cache *previousCache = cache[freq[key] - 1];

            if (previousCache->head->next == previousCache->tail)
                cache.erase(freq[key] - 1);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */