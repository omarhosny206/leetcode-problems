// https://leetcode.com/problems/word-search/

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[i].size(); ++j)
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0))
                    return true;

        return false;
    }

    bool dfs(vector<vector<char>> &board, string word, int i, int j, int position)
    {
        if (position == word.size())
            return true;

        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] == '.' || board[i][j] != word[position])
            return false;

        char temp = board[i][j];
        board[i][j] = '.';

        bool check = dfs(board, word, i + 1, j, position + 1) ||
                     dfs(board, word, i - 1, j, position + 1) ||
                     dfs(board, word, i, j + 1, position + 1) ||
                     dfs(board, word, i, j - 1, position + 1);

        board[i][j] = temp;

        return check;
    }
};