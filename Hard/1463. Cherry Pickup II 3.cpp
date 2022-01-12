// https://leetcode.com/problems/cherry-pickup-ii/

class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));
        return dfs(0, 0, grid[0].size() - 1, grid, dp);
    }

    int dfs(int i, int j, int k, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        if (i > grid.size() || j < 0 || j >= grid[0].size() || k < 0 || k >= grid[0].size())
            return 0;

        if (i == grid.size())
            return 0;

        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        int maxValue = 0;

        for (int p = -1; p <= 1; p++)
            for (int q = -1; q <= 1; q++)
                maxValue = max(maxValue, dfs(i + 1, j + p, k + q, grid, dp));

        dp[i][j][k] = maxValue + ((j == k) ? grid[i][j] : grid[i][j] + grid[i][k]);

        return dp[i][j][k];
    }
};