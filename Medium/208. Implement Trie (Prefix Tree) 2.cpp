// https://leetcode.com/problems/implement-trie-prefix-tree/

class TrieNode
{
public:
    vector<TrieNode *> children;
    bool isWord;

    TrieNode()
    {
        children = vector<TrieNode *>(26, nullptr);
        isWord = false;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *current = root;
        for (char c : word)
        {
            int charPosition = c - 'a';
            if (current->children[charPosition] == nullptr)
                current->children[charPosition] = new TrieNode();
            current = current->children[charPosition];
        }
        current->isWord = true;
    }

    bool search(string word)
    {
        TrieNode *current = root;
        for (char c : word)
        {
            int charPosition = c - 'a';
            if (current->children[charPosition] == nullptr)
                return false;
            current = current->children[charPosition];
        }

        return current->isWord;
    }

    bool startsWith(string prefix)
    {
        TrieNode *current = root;
        for (char c : prefix)
        {
            int charPosition = c - 'a';
            if (current->children[charPosition] == nullptr)
                return false;
            current = current->children[charPosition];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */