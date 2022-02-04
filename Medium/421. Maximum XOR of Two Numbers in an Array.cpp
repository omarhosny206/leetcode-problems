// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

class TrieNode
{
public:
    TrieNode *children[2];

    TrieNode()
    {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(int &number)
    {
        TrieNode *current = root;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (number >> i) & 1;

            if (current->children[bit] == nullptr)
                current->children[bit] = new TrieNode();

            current = current->children[bit];
        }
    }

    int getMax(int &number)
    {
        int result = 0;
        TrieNode *current = root;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (number >> i) & 1;

            int required = 1 - bit;

            if (current->children[required] != nullptr)
            {
                result = (result | (1 << i));
                current = current->children[required];
            }

            else
                current = current->children[bit];
        }

        return result;
    }
};

class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        int result = INT_MIN;
        Trie *trie = new Trie();

        for (int &num : nums)
            trie->insert(num);

        for (int &num : nums)
            result = max(result, trie->getMax(num));

        return result;
    }
};