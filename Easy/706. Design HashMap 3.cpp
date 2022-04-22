// https://leetcode.com/problems/design-hashmap/

class MyHashMap
{
    vector<int> values;
    const int SIZE = 1e6 + 1;

public:
    MyHashMap()
    {
        values = vector<int>(SIZE, -1);
    }

    void put(int key, int value)
    {
        values[key] = value;
    }

    int get(int key)
    {
        return values[key];
    }

    void remove(int key)
    {
        values[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */