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

    void insert(string word)
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

    vector<string> search(string prefix)
    {
        vector<string> words;
        TrieNode *current = root;

        for (int i = 0; i < prefix.size(); ++i)
        {
            if (current->children[prefix[i] - 'a'] == nullptr)
                return {};

            current = current->children[prefix[i] - 'a'];
        }

        dfs(current, words, prefix);
        return words;
    }

    void dfs(TrieNode *root, vector<string> &words, string &currentWord)
    {
        if (words.size() == 3)
            return;

        if (root->isWord == true)
            words.push_back(currentWord);

        for (int i = 0; i < root->children.size(); ++i)
        {
            if (root->children[i] != nullptr)
            {
                currentWord += (i + 'a');
                dfs(root->children[i], words, currentWord);
                currentWord.pop_back();
            }
        }
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