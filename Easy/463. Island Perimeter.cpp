// https://leetcode.com/problems/island-perimeter/

class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        if (grid.size() == 0)
            return 0;

        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[i].size(); ++j)
                if (grid[i][j] == 1)
                    return DFS(grid, i, j);

        return 0;
    }

    int DFS(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == 0)
            return 1;

        if (grid[i][j] == -1)
            return 0;

        int perimeter = 0;
        grid[i][j] = -1;

        perimeter += DFS(grid, i - 1, j) +
                     DFS(grid, i + 1, j) +
                     DFS(grid, i, j - 1) +
                     DFS(grid, i, j + 1);

        return perimeter;
    }
};