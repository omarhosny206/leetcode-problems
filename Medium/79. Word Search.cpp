// https://leetcode.com/problems/word-search/

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {

        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[i].size(); ++j)
                if (board[i][j] == word[0] && DFS(board, word, 0, i, j))
                    return true;

        return false;
    }

    bool DFS(vector<vector<char>> &board, string word, int index, int i, int j)
    {

        if (index == word.length())
            return true;

        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[index])
            return false;

        char letter = board[i][j];
        board[i][j] = ' ';

        bool isFound = DFS(board, word, index + 1, i, j - 1) || DFS(board, word, index + 1, i, j + 1) || DFS(board, word, index + 1, i - 1, j) || DFS(board, word, index + 1, i + 1, j);

        board[i][j] = letter;

        return isFound;
    }
};
