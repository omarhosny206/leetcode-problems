
class TrieNode
{
public:
    char val;
    int counter;
    vector<TrieNode *> children;

    TrieNode()
    {
        this->counter = 0;
        children = vector<TrieNode *>(26);
    }

    TrieNode(char val)
    {
        this->val = val;
        this->counter = 0;
        children = vector<TrieNode *>(26);
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        this->root = new TrieNode();
    }

    void insert(string &word)
    {
        TrieNode *current = root;

        for (char &c : word)
        {
            if (current->children[c - 'a'] == nullptr)
                current->children[c - 'a'] = new TrieNode(c);

            current = current->children[c - 'a'];
            current->counter++;
        }
    }

    int getScore(string &word)
    {
        int result = 0;
        TrieNode *current = root;

        for (char &c : word)
        {
            current = current->children[c - 'a'];
            result += current->counter;
        }

        return result;
    }
};

class Solution
{
public:
    vector<int> sumPrefixScores(vector<string> &words)
    {
        vector<int> result;
        Trie *trie = new Trie();

        for (string &word : words)
            trie->insert(word);

        for (string &word : words)
        {
            int score = trie->getScore(word);
            result.push_back(score);
        }

        return result;
    }
};