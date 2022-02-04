// https://leetcode.com/problems/design-add-and-search-words-data-structure/

class TrieNode
{
public:
    char val;
    vector<TrieNode *> children;
    bool isWord;

    TrieNode()
    {
        this->children = vector<TrieNode *>(26);
        this->isWord = false;
    }

    TrieNode(char val)
    {
        this->val = val;
        this->children = vector<TrieNode *>(26);
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

    void insert(string &word)
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

    bool search(string &word)
    {
        TrieNode *current = root;
        return dfs(current, word, 0);
    }

    bool dfs(TrieNode *root, string &word, int position)
    {
        bool result = false;

        if (position == word.length())
            return root->isWord;

        if (word[position] == '.')
        {
            for (int i = 0; i < root->children.size(); ++i)
                if (root->children[i])
                    result = result || dfs(root->children[i], word, position + 1);
        }

        else if (root->children[word[position] - 'a'])
            result = dfs(root->children[word[position] - 'a'], word, position + 1);

        return result;
    }
};

class WordDictionary
{
    Trie *trie;

public:
    /** Initialize your data structure here. */
    WordDictionary()
    {
        trie = new Trie();
    }

    void addWord(string word)
    {
        trie->insert(word);
    }

    bool search(string word)
    {
        return trie->search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */