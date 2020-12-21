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

    TrieNode(char v)
    {
        this->val = v;
        this->isWord = false;
    }
};

class Solution
{
    vector<string> result;
    TrieNode *root;

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        root = new TrieNode();

        for (string word : words)
            insert(word);

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); j++)
                DFS(board, i, j, root);
        }

        return result;
    }

    void DFS(vector<vector<char>> &board, int i, int j, TrieNode *root)
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

            DFS(board, i - 1, j, root->children[temp]);
            DFS(board, i + 1, j, root->children[temp]);
            DFS(board, i, j - 1, root->children[temp]);
            DFS(board, i, j + 1, root->children[temp]);

            board[i][j] = temp;
        }

        return;
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
};