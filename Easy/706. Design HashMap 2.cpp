// https://leetcode.com/problems/design-hashmap/

class MyHashMap
{
    int numBuckets;
    vector<list<pair<int, int>>> buckets;

public:
    MyHashMap()
    {
        numBuckets = 15000;
        buckets = vector<list<pair<int, int>>>(numBuckets);
    }

    void put(int key, int value)
    {
        int index = hash(key);

        for (auto &pair : buckets[index])
        {
            if (pair.first == key)
            {
                pair.second = value;
                return;
            }
        }

        buckets[index].push_back({key, value});
    }

    int get(int key)
    {
        int index = hash(key);

        for (auto &pair : buckets[index])
            if (pair.first == key)
                return pair.second;

        return -1;
    }

    void remove(int key)
    {
        int index = hash(key);

        for (auto &pair : buckets[index])
        {
            if (pair.first == key)
            {
                buckets[index].remove(pair);
                return;
            }
        }
    }

    int hash(int key)
    {
        return key % numBuckets;
    }
};