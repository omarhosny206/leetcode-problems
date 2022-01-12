// https://leetcode.com/problems/cherry-pickup-ii/

class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));

        for (int i = grid.size() - 1; i >= 0; i--)
        {
            for (int j = grid[0].size() - 1; j >= 0; j--)
            {
                for (int k = grid[0].size() - 1; k >= 0; k--)
                {
                    if (i == grid.size() - 1)
                        dp[i][j][k] = (j == k) ? grid[i][j] : grid[i][j] + grid[i][k];

                    else
                    {
                        int maxValue = 0;

                        for (int p = -1; p <= 1; p++)
                            for (int q = -1; q <= 1; q++)
                                if (j + p >= 0 && j + p < grid[0].size() && k + q >= 0 && k + q < grid[0].size())
                                    maxValue = max(maxValue, dp[i + 1][j + p][k + q]);

                        dp[i][j][k] = maxValue + ((j == k) ? grid[i][j] : grid[i][j] + grid[i][k]);
                    }
                }
            }
        }

        return dp[0][0][grid[0].size() - 1];
    }
};