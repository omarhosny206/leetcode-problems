// https://leetcode.com/problems/implement-trie-prefix-tree/

class TrieNode
{
public:
    char val;
    unordered_map<char, TrieNode *> children;
    bool isWord;
    TrieNode()
    {
    }

    TrieNode(char v)
    {
        this->val = v;
        this->isWord = false;
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
            if (current->children.find(c) == current->children.end())
                current->children[c] = new TrieNode(c);

            current = current->children[c];
        }

        current->isWord = true;
    }

    bool search(string word)
    {
        TrieNode *current = root;
        for (char c : word)
        {
            if (current->children.find(c) == current->children.end())
                return false;
            current = current->children[c];
        }

        return current->isWord;
    }

    bool startsWith(string prefix)
    {
        TrieNode *current = root;
        for (char c : prefix)
        {
            if (current->children.find(c) == current->children.end())
                return false;
            current = current->children[c];
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