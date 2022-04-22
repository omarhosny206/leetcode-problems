// https://leetcode.com/problems/design-hashmap/

class Node
{
public:
    int key;
    int value;

    Node(int key, int value)
    {
        this->value = value;
        this->key = key;
    }
};

class MyHashMap
{
    int numBuckets;
    vector<list<Node *>> buckets;

public:
    MyHashMap()
    {
        numBuckets = 15000;
        buckets = vector<list<Node *>>(numBuckets);
    }

    void put(int key, int value)
    {
        int index = hash(key);

        for (Node *&node : buckets[index])
        {
            if (node->key == key)
            {
                node->value = value;
                return;
            }
        }

        buckets[index].push_back(new Node(key, value));
    }

    int get(int key)
    {
        int index = hash(key);

        for (Node *&node : buckets[index])
            if (node->key == key)
                return node->value;

        return -1;
    }

    void remove(int key)
    {
        int index = hash(key);

        for (auto iterator = buckets[index].begin(); iterator != buckets[index].end(); ++iterator)
        {
            if ((*iterator)->key == key)
            {
                buckets[index].remove(*iterator);
                return;
            }
        }
    }

    int hash(int key)
    {
        return key % numBuckets;
    }
};