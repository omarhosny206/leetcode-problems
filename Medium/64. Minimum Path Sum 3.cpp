// https://leetcode.com/problems/minimum-path-sum/

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int result;
        vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size(), 0));

        result = getPathValue(grid, memo, 0, 0);

        return result;
    }

    int getPathValue(vector<vector<int>> &grid, vector<vector<int>> &memo, int i, int j)
    {
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
            return grid[grid.size() - 1][grid[0].size() - 1];

        if (i >= grid.size() || j >= grid[0].size())
            return 1e+8;

        if (memo[i][j] != 0)
            return memo[i][j];

        memo[i][j] = grid[i][j] + min({getPathValue(grid, memo, i + 1, j),
                                       getPathValue(grid, memo, i, j + 1)});

        return memo[i][j];
    }
};