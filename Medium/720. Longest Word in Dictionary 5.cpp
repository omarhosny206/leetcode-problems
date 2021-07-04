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

    bool Search(string &word)
    {
        TrieNode *current = root;

        for (char &c : word)
        {
            if (!current->children[c - 'a'])
                return false;

            current = current->children[c - 'a'];
        }

        return current->isWord;
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
        {
            string prefix = "";
            int counter = 0;

            for (char &c : word)
            {
                prefix += c;

                if (trie->Search(prefix) == false)
                    break;

                counter++;
            }

            if (counter == word.length() && result.length() < word.length())
                result = word;
        }

        return result;
    }
};