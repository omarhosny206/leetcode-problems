// https://leetcode.com/problems/camelcase-matching/

class TrieNode
{
public:
    char val;
    unordered_map<char, TrieNode *> children;
    bool isWord;

    TrieNode()
    {
        this->isWord = false;
    }

    TrieNode(char val)
    {
        this->val = val;
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

    void Insert(string &word)
    {
        TrieNode *current = root;

        for (char &c : word)
        {
            if (current->children.find(c) == current->children.end())
                current->children[c] = new TrieNode(c);

            current = current->children[c];
        }

        current->isWord = true;
    }

    bool canForm(string &word)
    {
        TrieNode *current = root;

        for (char &c : word)
        {
            if (current->children.find(c) == current->children.end() && isupper(c))
                return false;

            if (current->children.find(c) != current->children.end())
                current = current->children[c];
        }

        return current->isWord;
    }
};

class Solution
{
public:
    vector<bool> camelMatch(vector<string> &queries, string pattern)
    {
        vector<bool> result;
        Trie *trie = new Trie();

        trie->Insert(pattern);

        for (string &query : queries)
            result.push_back(trie->canForm(query));

        return result;
    }
};