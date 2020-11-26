// https://leetcode.com/problems/longest-common-prefix/
class TrieNode
{
public:
    vector<TrieNode *> children;
    int letterCounter;
    bool isWord;

    TrieNode()
    {
        children = vector<TrieNode *>(26, nullptr);
        letterCounter = 0;
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

    void insert(string word)
    {
        TrieNode *current = root;
        for (char c : word)
        {
            int charPosition = c - 'a';
            if (current->children[charPosition] == nullptr)
                current->children[charPosition] = new TrieNode();

            current = current->children[charPosition];
            current->letterCounter++;
        }
        current->isWord = true;
    }

    string getLCP(string word, int size)
    {
        string LCP = "";
        TrieNode *current = root;
        for (char c : word)
        {
            int charPosition = c - 'a';
            if (current->children[charPosition]->letterCounter != size)
                break;

            current = current->children[charPosition];
            LCP += c;
        }

        return LCP;
    }
};

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
            return "";

        Trie *trie = new Trie();

        for (string word : strs)
            trie->insert(word);

        string LCP = trie->getLCP(strs[0], strs.size());

        return LCP;
    }
};