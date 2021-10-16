// https://leetcode.com/problems/word-search-ii/

class TrieNode
{
public:
    char val;
    unordered_map<char, TrieNode *> children;
    bool isWord;
    string word;

    TrieNode()
    {
        this->isWord = false;
        this->word = "";
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
        current->word = word;
    }

    void DFS(vector<string> &result, vector<vector<char>> &board, int i, int j, TrieNode *root)
    {
        if (root->isWord)
        {
            result.push_back(root->word);
            root->isWord = false;
        }

        if (i < 0 || j < 0 || i >= board.size() || j >= board[i].size() || board[i][j] == '.')
        {
            return;
        }

        if (root->children.find(board[i][j]) != root->children.end())
        {
            char temp = board[i][j];
            board[i][j] = '.';

            DFS(result, board, i - 1, j, root->children[temp]);
            DFS(result, board, i + 1, j, root->children[temp]);
            DFS(result, board, i, j - 1, root->children[temp]);
            DFS(result, board, i, j + 1, root->children[temp]);

            board[i][j] = temp;
        }
    }
};

class Solution
{
    vector<string> result;
    Trie *trie;

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        trie = new Trie();

        for (string word : words)
            trie->insert(word);

        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[i].size(); j++)
                trie->DFS(result, board, i, j, trie->root);

        return result;
    }
};