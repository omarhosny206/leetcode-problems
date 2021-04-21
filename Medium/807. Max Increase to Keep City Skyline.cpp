// https://leetcode.com/problems/max-increase-to-keep-city-skyline/

class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        int result = 0;
        vector<int> maxRow(grid.size());
        vector<int> maxColumn(grid[0].size());

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                maxRow[i] = max(maxRow[i], grid[i][j]);
                maxColumn[j] = max(maxColumn[j], grid[i][j]);
            }
        }

        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[i].size(); ++j)
                result += min(maxRow[i], maxColumn[j]) - grid[i][j];

        return result;
    }
};