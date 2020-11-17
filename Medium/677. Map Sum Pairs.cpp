// https://leetcode.com/problems/map-sum-pairs/

class MapSum
{
    class TrieNode
    {
    public:
        TrieNode *child[26];
        int end;
        TrieNode()
        {
            for (int i = 0; i < 26; i++)
                child[i] = NULL;
            end = 0;
        }
    };
    TrieNode *root;

public:
    MapSum()
    {
        root = new TrieNode();
    }

    void insert(string key, int val)
    {
        TrieNode *current = root;
        for (int i = 0; i < key.size(); i++)
        {
            int idx = key[i] - 'a';
            if (!current->child[idx])
                current->child[idx] = new TrieNode();
            current = current->child[idx];
        }
        current->end = val;
    }

    int sumFromHere(TrieNode *current)
    {
        int sum = current->end;
        for (int i = 0; i < 26; i++)
            if (current->child[i])
                sum += sumFromHere(current->child[i]);

        return sum;
    }

    int sum(string prefix)
    {
        TrieNode *current = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            int idx = prefix[i] - 'a';
            if (current->child[idx])
                current = current->child[idx];
            else
                return 0;
        }
        return sumFromHere(current);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */