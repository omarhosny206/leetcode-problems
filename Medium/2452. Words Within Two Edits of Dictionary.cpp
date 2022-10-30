// https://leetcode.com/problems/words-within-two-edits-of-dictionary/

class TrieNode
{
public:
    char val;
    vector<TrieNode *> children;
    bool isWord;

    TrieNode()
    {
        children = vector<TrieNode *>(26);
        isWord = false;
    }

    TrieNode(char val)
    {
        this->val = val;
        children = vector<TrieNode *>(26);
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

    void insert(string &word)
    {
        TrieNode *current = root;

        for (char &c : word)
        {
            if (current->children[c - 'a'] == nullptr)
                current->children[c - 'a'] = new TrieNode(c);

            current = current->children[c - 'a'];
        }

        current->isWord = true;
    }

    bool search(string &word, int i, int editAttempts)
    {
        TrieNode *current = root;
        return dfs(current, word, i, editAttempts);
    }

    bool dfs(TrieNode *current, string &word, int i, int editAttempts)
    {
        bool result = false;

        if (editAttempts < 0)
            return false;

        if (i == word.length())
            return current->isWord;

        for (int j = 0; j < 26; ++j)
        {
            if (current->children[j] != nullptr)
            {
                if ((j + 'a') == word[i])
                    result = result || dfs(current->children[j], word, i + 1, editAttempts);

                else
                    result = result || dfs(current->children[j], word, i + 1, editAttempts - 1);
            }
        }

        return result;
    }
};

class Solution
{
public:
    vector<string> twoEditWords(vector<string> &queries, vector<string> &dictionary)
    {
        vector<string> result;
        Trie *trie = new Trie();
        const int MAX_EDIT_ATTEMPTS = 2;

        for (string &word : dictionary)
            trie->insert(word);

        for (string &word : queries)
            if (trie->search(word, 0, MAX_EDIT_ATTEMPTS))
                result.push_back(word);

        return result;
    }
};