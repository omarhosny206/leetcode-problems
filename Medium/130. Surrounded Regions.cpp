// https://leetcode.com/problems/surrounded-regions/

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        markVerticalBoarderRegions(board);
        markHorizontalBoarderRegions(board);
        flipRegions(board);
    }

    void flipRegions(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == 'W')
                    board[i][j] = 'O';

                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }

    void DFS(vector<vector<char>> &board, int i, int j)
    {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != 'O')
            return;

        board[i][j] = 'W';
        DFS(board, i + 1, j);
        DFS(board, i - 1, j);
        DFS(board, i, j + 1);
        DFS(board, i, j - 1);
    }

    void markVerticalBoarderRegions(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); ++i)
        {
            DFS(board, i, 0);
            DFS(board, i, board[0].size() - 1);
        }
    }

    void markHorizontalBoarderRegions(vector<vector<char>> &board)
    {
        for (int j = 0; j < board[0].size(); ++j)
        {
            DFS(board, 0, j);
            DFS(board, board.size() - 1, j);
        }
    }
};