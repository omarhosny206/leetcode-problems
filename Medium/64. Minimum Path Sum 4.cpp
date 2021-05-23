// https://leetcode.com/problems/minimum-path-sum/

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> paths(m, vector<int>(n));

        paths[0][0] = grid[0][0];

        for (int i = 1; i < m; ++i)
            paths[i][0] = grid[i][0] + paths[i - 1][0];

        for (int i = 1; i < n; ++i)
            paths[0][i] = grid[0][i] + paths[0][i - 1];

        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                paths[i][j] = min(paths[i][j - 1] + grid[i][j], paths[i - 1][j] + grid[i][j]);

        return paths[m - 1][n - 1];
    }
};