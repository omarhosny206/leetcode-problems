// https://leetcode.com/problems/available-captures-for-rook/

class Solution
{
public:
    int numRookCaptures(vector<vector<char>> &board)
    {
        int result = 0;

        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[i].size(); ++j)
                if (board[i][j] == 'R')
                    result = countCaptures(board, i, j);

        return result;
    }

    int countCaptures(vector<vector<char>> &board, int i, int j)
    {
        int result = 0;

        result += checkUp(board, i, j);
        result += checkLeft(board, i, j);
        result += checkDown(board, i, j);
        result += checkRight(board, i, j);

        return result;
    }

    int checkUp(vector<vector<char>> &board, int i, int j)
    {
        int result = 0;
        int temp = result;

        while (i >= 0 && !isBishop(board[i][j]) && temp == result)
        {
            if (isPawn(board[i][j]))
                result++;

            i--;
        }

        return result;
    }

    int checkLeft(vector<vector<char>> &board, int i, int j)
    {
        int result = 0;
        int temp = result;

        while (j >= 0 && !isBishop(board[i][j]) && temp == result)
        {
            if (isPawn(board[i][j]))
                result++;

            j--;
        }

        return result;
    }

    int checkDown(vector<vector<char>> &board, int i, int j)
    {
        int result = 0;
        int temp = result;

        while (i < board.size() && !isBishop(board[i][j]) && temp == result)
        {
            if (isPawn(board[i][j]))
                result++;

            i++;
        }

        return result;
    }

    int checkRight(vector<vector<char>> &board, int i, int j)
    {
        int result = 0;
        int temp = result;

        while (j < board[i].size() && !isBishop(board[i][j]) && temp == result)
        {
            if (isPawn(board[i][j]))
                result++;

            j++;
        }

        return result;
    }

    bool isPawn(char &c)
    {
        return c == 'p';
    }

    bool isBishop(char &c)
    {
        return c == 'B';
    }
};