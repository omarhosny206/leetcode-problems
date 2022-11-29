// https://leetcode.com/problems/insert-delete-getrandom-o1/

class RandomizedSet
{
    unordered_map<int, int> position;
    vector<int> vals;

public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (position.find(val) != position.end())
            return false;

        vals.push_back(val);
        position[val] = vals.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (position.find(val) == position.end())
            return false;

        int valToRemovePosition = position[val];
        int lastValPosition = vals.size() - 1;
        swap(valToRemovePosition, lastValPosition);

        position[vals[valToRemovePosition]] = valToRemovePosition;

        vals.pop_back();
        position.erase(val);
        return true;
    }

    int getRandom()
    {
        int randomPosition = rand() % vals.size();
        return vals[randomPosition];
    }

    void swap(int i, int j)
    {
        int temp = vals[i];
        vals[i] = vals[j];
        vals[j] = temp;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */