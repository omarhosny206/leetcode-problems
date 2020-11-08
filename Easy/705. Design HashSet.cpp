// https://leetcode.com/problems/design-hashset/

class MyHashSet
{
    vector<bool> HashSet;

public:
    /** Initialize your data structure here. */
    MyHashSet()
    {
        HashSet = vector<bool>(1000000, false);
    }

    void add(int key)
    {
        HashSet[key] = true;
    }

    void remove(int key)
    {
        HashSet[key] = false;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        return HashSet[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */