// https://leetcode.com/problems/maximum-sum-of-an-hourglass/

class Solution
{
public:
    int maxSum(vector<vector<int>> &grid)
    {
        int result = 0;

        for (int i = 1; i < grid.size() - 1; ++i)
            for (int j = 1; j < grid[0].size() - 1; ++j)
                result = max(result, countHourglass(grid, i, j));

        return result;
    }

    int countHourglass(vector<vector<int>> &grid, int i, int j)
    {
        int current = grid[i][j];
        int up = grid[i - 1][j] + grid[i - 1][j + 1] + grid[i - 1][j - 1];
        int down = grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j - 1];

        return current + up + down;
    }
};