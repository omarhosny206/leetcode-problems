// https://leetcode.com/problems/path-with-maximum-gold/

class Solution
{
public:
    int getMaximumGold(vector<vector<int>> &grid)
    {
        int maximumGold = INT_MIN;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[i].size(); ++j)
                if (grid[i][j] != 0)
                    maximumGold = max(maximumGold, DFS(grid, i, j));

        return maximumGold;
    }

    int DFS(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == 0)
            return 0;

        int path = grid[i][j];
        int temp = grid[i][j];
        grid[i][j] = 0;

        path += max({DFS(grid, i + 1, j),
                     DFS(grid, i - 1, j),
                     DFS(grid, i, j + 1),
                     DFS(grid, i, j - 1)});

        grid[i][j] = temp;

        return path;
    }
};