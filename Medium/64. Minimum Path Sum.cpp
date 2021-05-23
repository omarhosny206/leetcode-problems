// https://leetcode.com/problems/minimum-path-sum/

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        for (int j = grid[0].size() - 2; j >= 0; --j)
            grid[grid.size() - 1][j] += grid[grid.size() - 1][j + 1];

        for (int i = grid.size() - 2; i >= 0; --i)
            for (int j = grid[0].size() - 1; j >= 0; --j)
                grid[i][j] += min({getValue(grid, i + 1, j), getValue(grid, i, j + 1)});

        return grid[0][0];
    }

    int getValue(vector<vector<int>> &grid, int i, int j)
    {
        if (j >= grid[0].size())
            return 1e+8;

        return grid[i][j];
    }
};