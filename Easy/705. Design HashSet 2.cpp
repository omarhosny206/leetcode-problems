// https://leetcode.com/problems/design-hashset/

class MyHashSet
{
    int numBuckets;
    vector<list<int>> buckets;

public:
    MyHashSet()
    {
        numBuckets = 15000;
        buckets = vector<list<int>>(numBuckets);
    }

    void add(int key)
    {
        if (contains(key))
            return;

        int index = hashFunction(key);
        buckets[index].push_back(key);
    }

    void remove(int key)
    {
        int index = hashFunction(key);
        auto position = find(buckets[index].begin(), buckets[index].end(), key);

        if (position != buckets[index].end())
            buckets[index].erase(position);
    }

    bool contains(int key)
    {
        int index = hashFunction(key);
        return search(buckets[index], key);
    }

    bool search(list<int> values, int key)
    {
        for (int &value : values)
            if (value == key)
                return true;

        return false;
    }

    int hashFunction(int key)
    {
        return key % numBuckets;
    }
};
/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */