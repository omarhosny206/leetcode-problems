// https://leetcode.com/problems/number-of-closed-islands/

class Solution
{
public:
    int closedIsland(vector<vector<int>> &grid)
    {
        int closed_islands = 0;
        int r = grid.size();
        int c = grid[0].size();

        for (int i = 0; i < r; ++i)
        {
            DFS(grid, i, 0);
            DFS(grid, i, c - 1);
        }

        for (int j = 0; j < c; ++j)
        {
            DFS(grid, 0, j);
            DFS(grid, r - 1, j);
        }

        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (grid[i][j] == 0)
                {
                    closed_islands++;
                    DFS(grid, i, j);
                }
            }
        }

        return closed_islands;
    }

    void DFS(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == 1)
            return;

        grid[i][j] = 1;
        DFS(grid, i, j - 1);
        DFS(grid, i, j + 1);
        DFS(grid, i - 1, j);
        DFS(grid, i + 1, j);
    }
};