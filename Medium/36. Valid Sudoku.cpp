// https://leetcode.com/problems/valid-sudoku/

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); ++i)
        {
            bool isRowOk = checkRow(board, i);
            bool isColumnOk = checkColumn(board, i);
            bool isSubBoxOk = true;

            if (i % 3 == 0)
                isSubBoxOk = checkSubBox(board, i);

            bool areAllOk = isRowOk && isColumnOk && isSubBoxOk;

            if (!areAllOk)
                return false;
        }

        return true;
    }

    bool checkRow(vector<vector<char>> &board, int row)
    {
        unordered_set<char> values;

        for (int j = 0; j < board[row].size(); ++j)
        {
            if (isValidCell(board[row][j]) && values.find(board[row][j]) != values.end())
                return false;

            values.insert(board[row][j]);
        }

        return true;
    }

    bool checkColumn(vector<vector<char>> &board, int column)
    {
        unordered_set<char> values;

        for (int i = 0; i < board.size(); ++i)
        {
            if (isValidCell(board[i][column]) && values.find(board[i][column]) != values.end())
                return false;

            values.insert(board[i][column]);
        }

        return true;
    }

    bool checkSubBox(vector<vector<char>> &board, int row)
    {
        int numSumBoxes = 3;
        int column = 0;

        while (numSumBoxes--)
        {
            unordered_set<char> values;

            for (int i = row; i < row + 3; ++i)
            {
                for (int j = column; j < column + 3; ++j)
                {
                    if (isValidCell(board[i][j]) && values.find(board[i][j]) != values.end())
                        return false;

                    values.insert(board[i][j]);
                }
            }

            column += 3;
        }

        return true;
    }

    bool isValidCell(char &c)
    {
        return c >= '1' && c <= '9';
    }
};