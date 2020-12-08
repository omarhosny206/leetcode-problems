// https://leetcode.com/problems/maximal-square/

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {

        if (matrix.size() == 0)
            return 0;

        int rows = matrix.size();
        int columns = matrix[0].size();

        vector<vector<int>> dp(rows, vector<int>(columns, 0));
        int answer = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                dp[i][j] = matrix[i][j] - '0';
                answer = max(answer, dp[i][j]);
            }
        }

        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < columns; j++)
            {
                if (dp[i][j] == 1)
                {
                    int curr_min = min(dp[i - 1][j], dp[i][j - 1]);
                    curr_min = min(dp[i - 1][j - 1], curr_min);
                    dp[i][j] = curr_min + 1;
                    answer = max(answer, dp[i][j]);
                }
            }
        }
        return answer * answer;
    }
};