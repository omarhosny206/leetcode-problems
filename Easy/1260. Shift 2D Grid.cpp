// https://leetcode.com/problems/shift-2d-grid/

class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        vector<vector<int>> result(grid.size(), vector<int>(grid[0].size()));

        int rows = grid.size();
        int columns = grid[0].size();

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                int newColumn = (j + k) % columns;
                int newRow = (i + (j + k) / columns) % rows;
                result[newRow][newColumn] = grid[i][j];
            }
        }

        return result;
    }
};