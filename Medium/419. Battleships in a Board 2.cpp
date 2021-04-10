// https://leetcode.com/problems/battleships-in-a-board/

class Solution
{
public:
    int countBattleships(vector<vector<char>> &board)
    {
        int result = 0;

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] == 'X')
                {
                    result++;
                    DFS(board, i, j);
                }
            }
        }

        return result;
    }

    void DFS(vector<vector<char>> &board, int i, int j)
    {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[i].size() || board[i][j] == '.')
            return;

        board[i][j] = '.';
        DFS(board, i + 1, j);
        DFS(board, i - 1, j);
        DFS(board, i, j + 1);
        DFS(board, i, j - 1);
    }
};