// https://leetcode.com/problems/design-hashmap/

class MyHashMap
{

    int numBuckets;
    vector<list<pair<int, int>>> buckets;

    int hash(int key)
    {
        return key % numBuckets;
    }

public:
    MyHashMap()
    {
        numBuckets = 15000;
        buckets = vector<list<pair<int, int>>>(numBuckets, list<pair<int, int>>{});
    }

    void put(int key, int value)
    {
        pair<int, int> val(key, value);
        int i = hash(key);

        for (auto it = buckets[i].begin(); it != buckets[i].end(); ++it)
        {
            if (it->first == key)
            {
                it->second = value;
            }
        }

        buckets[i].push_back(val);
    }

    int get(int key)
    {
        int i = hash(key);
        for (auto it = buckets[i].begin(); it != buckets[i].end(); ++it)
        {
            if (it->first == key)
            {
                return it->second;
            }
        }

        return -1;
    }

    void remove(int key)
    {
        int i = hash(key);
        for (auto it = buckets[i].begin(); it != buckets[i].end(); ++it)
        {
            if (it->first == key)
            {
                buckets[i].remove(*it);
                return;
            }
        }

        return;
    }
};