// https://leetcode.com/problems/replace-words/

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

    string search(string word)
    {
        string result = "";
        TrieNode *current = root;
        for (char c : word)
        {
            if (current->children.find(c) == current->children.end())
                return word;

            result += c;
            current = current->children[c];

            if (current->isWord)
                return result;
        }

        return word;
    }
};

class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        string result = "";
        Trie trie;

        for (string root : dictionary)
            trie.insert(root);

        istringstream words(sentence);
        string word = "";

        while (words >> word)
        {
            result += trie.search(word) + ' ';
        }

        result.pop_back();
        return result;
    }
};