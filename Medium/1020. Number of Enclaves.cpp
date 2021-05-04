// https://leetcode.com/problems/number-of-enclaves/

class Solution
{
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int result = 0;
        int rows = grid.size();
        int columns = grid[0].size();

        for (int i = 0; i < rows; ++i)
        {
            DFS(grid, i, 0);
            DFS(grid, i, columns - 1);
        }

        for (int j = 0; j < columns; ++j)
        {
            DFS(grid, 0, j);
            DFS(grid, rows - 1, j);
        }

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < columns; ++j)
                if (grid[i][j] == 1)
                    result++;

        return result;
    }

    void DFS(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == 0)
            return;

        grid[i][j] = 0;
        DFS(grid, i + 1, j);
        DFS(grid, i - 1, j);
        DFS(grid, i, j + 1);
        DFS(grid, i, j - 1);
    }
};