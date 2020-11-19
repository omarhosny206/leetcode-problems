// https://leetcode.com/problems/max-area-of-island/

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int max_area = 0;

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == 1)
                    max_area = max(max_area, DFS(grid, i, j));
        }

        return max_area;
    }

    int DFS(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] != 1)
            return 0;

        grid[i][j] = 0;
        int count = 1;
        count += DFS(grid, i, j - 1) + DFS(grid, i, j + 1) + DFS(grid, i - 1, j) + DFS(grid, i + 1, j);

        return count;
    }
};