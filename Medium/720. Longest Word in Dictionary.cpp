// https://leetcode.com/problems/longest-word-in-dictionary/

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

    void Insert(string &word)
    {
        TrieNode *current = root;

        for (char &c : word)
        {
            if (!current->children[c - 'a'])
                current->children[c - 'a'] = new TrieNode(c);

            current = current->children[c - 'a'];
        }

        current->isWord = true;
    }

    bool canBuild(string &word)
    {
        TrieNode *current = root;

        for (char &c : word)
        {
            current = current->children[c - 'a'];

            if (!current->isWord)
                return false;
        }

        return true;
    }
};

class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        string result = "";
        Trie *trie = new Trie();

        sort(words.begin(), words.end());

        for (string &word : words)
            trie->Insert(word);

        for (string &word : words)
            if (trie->canBuild(word) == true && result.length() < word.length())
                result = word;

        return result;
    }
};