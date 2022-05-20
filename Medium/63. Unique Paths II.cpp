// https://leetcode.com/problems/unique-paths-ii/

class Solution
{
    int result = 0;

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        return dfs(obstacleGrid, dp, 0, 0);
    }

    int dfs(vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp, int i, int j)
    {
        if (i >= obstacleGrid.size() || i < 0 || j >= obstacleGrid[i].size() || j < 0 || obstacleGrid[i][j] != 0)
            return 0;

        if (i == obstacleGrid.size() - 1 && j == obstacleGrid[i].size() - 1)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        obstacleGrid[i][j] = 2;
        dp[i][j] = dfs(obstacleGrid, dp, i + 1, j) + dfs(obstacleGrid, dp, i, j + 1);
        obstacleGrid[i][j] = 0;

        return dp[i][j];
    }
};