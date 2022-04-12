// https://leetcode.com/problems/game-of-life/

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                int counter = 0;

                for (vector<int> &direction : directions)
                {
                    int row = i + direction[0];
                    int column = j + direction[1];

                    if (isValidPosition(board, row, column) && board[row][column] % 2 == 1)
                        counter++;
                }

                if (board[i][j] == 1)
                {
                    if (counter < 2 || counter > 3)
                        board[i][j] = 3;
                }

                else if (counter == 3)
                    board[i][j] = 2;
            }
        }

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] == 3)
                    board[i][j] = 0;

                else if (board[i][j] == 2)
                    board[i][j] = 1;
            }
        }
    }

    bool isValidPosition(vector<vector<int>> &board, int i, int j)
    {
        return i < board.size() && i >= 0 && j < board[i].size() && j >= 0;
    }
};