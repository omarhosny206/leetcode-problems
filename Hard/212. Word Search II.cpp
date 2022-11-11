// https://leetcode.com/problems/word-search-ii/

class TrieNode
{
public:
    char val;
    TrieNode *children[26] = {nullptr};
    bool isWord;
    string word;

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

    void insert(string word)
    {
        TrieNode *current = root;

        for (char &c : word)
        {
            if (current->children[c - 'a'] == nullptr)
                current->children[c - 'a'] = new TrieNode(c);

            current = current->children[c - 'a'];
        }

        current->isWord = true;
        current->word = word;
    }

    void dfs(vector<string> &result, vector<vector<char>> &board, int i, int j, TrieNode *current)
    {
        if (current->isWord)
        {
            result.push_back(current->word);
            current->isWord = false;
            current->word = "";
        }

        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] == '.')
            return;

        if (current->children[board[i][j] - 'a'] != nullptr)
        {
            char temp = board[i][j];
            board[i][j] = '.';

            dfs(result, board, i + 1, j, current->children[temp - 'a']);
            dfs(result, board, i - 1, j, current->children[temp - 'a']);
            dfs(result, board, i, j + 1, current->children[temp - 'a']);
            dfs(result, board, i, j - 1, current->children[temp - 'a']);

            board[i][j] = temp;
        }
    }
};

class Solution
{
    vector<string> result;

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        Trie *trie = new Trie();

        for (string &word : words)
            trie->insert(word);

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                TrieNode *current = trie->root;
                trie->dfs(result, board, i, j, current);
            }
        }

        return result;
    }
};