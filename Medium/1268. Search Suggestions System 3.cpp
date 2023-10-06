// https://leetcode.com/problems/search-suggestions-system/

class TrieNode
{
public:
    char val;
    map<char, TrieNode *> children;
    bool isWord;

    TrieNode()
    {
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
    vector<vector<string>> result;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
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

    vector<string> search(string prefix)
    {
        vector<string> words;
        TrieNode *current = root;

        for (char &c : prefix)
        {
            if (current->children.find(c) == current->children.end())
                return words;

            current = current->children[c];
        }

        dfs(current, words, prefix);
        return words;
    }

    void dfs(TrieNode *root, vector<string> &words, string currentWord)
    {
        if (words.size() == 3)
            return;

        if (root->isWord == true)
            words.push_back(currentWord);

        for (auto pair : root->children)
            dfs(root->children[pair.first], words, currentWord + pair.first);
    }
};

class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        vector<vector<string>> result;
        Trie *trie = new Trie();
        string prefix = "";

        for (string &product : products)
            trie->insert(product);

        for (char &c : searchWord)
        {
            prefix += c;
            result.push_back(trie->search(prefix));
        }

        return result;
    }
};