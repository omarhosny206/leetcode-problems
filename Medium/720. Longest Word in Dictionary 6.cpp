// https://leetcode.com/problems/longest-word-in-dictionary/

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

    bool Search(string &word)
    {
        TrieNode *current = root;

        for (char &c : word)
        {
            if (current->children.find(c) == current->children.end())
                return false;

            current = current->children[c];
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