// https://leetcode.com/problems/design-hashset/

class MyHashSet
{
    vector<bool> seen;
    const int SIZE = 1e6 + 1;

public:
    MyHashSet()
    {
        seen = vector<bool>(SIZE, false);
    }

    void add(int key)
    {
        seen[key] = true;
    }

    void remove(int key)
    {
        seen[key] = false;
    }

    bool contains(int key)
    {
        return seen[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */