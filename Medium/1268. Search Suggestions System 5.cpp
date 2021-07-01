// https://leetcode.com/problems/search-suggestions-system/

class TrieNode
{
public:
    char val;
    vector<TrieNode *> children;
    bool isWord;

    TrieNode()
    {
        children = vector<TrieNode *>(26);
        this->isWord = false;
    }

    TrieNode(char val)
    {
        this->val = val;
        children = vector<TrieNode *>(26);
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

    void Insert(string word)
    {
        TrieNode *current = root;

        for (int i = 0; i < word.size(); ++i)
        {
            if (!current->children[word[i] - 'a'])
                current->children[word[i] - 'a'] = new TrieNode(word[i]);

            current = current->children[word[i] - 'a'];
        }

        current->isWord = true;
    }

    vector<string> Search(string prefix)
    {
        vector<string> words;
        TrieNode *current = root;

        for (int i = 0; i < prefix.size(); ++i)
        {
            if (current->children[prefix[i] - 'a'] == nullptr)
                return {};

            current = current->children[prefix[i] - 'a'];
        }

        DFS(current, words, prefix);
        return words;
    }

    void DFS(TrieNode *root, vector<string> &words, string currentWord)
    {
        if (words.size() == 3)
            return;

        if (root->isWord == true)
            words.push_back(currentWord);

        for (int i = 0; i < root->children.size(); ++i)
            if (root->children[i] != nullptr)
                DFS(root->children[i], words, currentWord + (char)(i + 'a'));
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
            trie->Insert(product);

        for (char &c : searchWord)
        {
            prefix += c;
            result.push_back(trie->Search(prefix));
        }

        return result;
    }
};