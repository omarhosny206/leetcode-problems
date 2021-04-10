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
                if (board[i][j] == 'X' && (!i || board[i - 1][j] != 'X') && (!j || board[i][j - 1] != 'X'))
                    result++;
            }
        }

        return result;
    }
};