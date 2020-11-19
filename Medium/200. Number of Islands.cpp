// https://leetcode.com/problems/number-of-islands/

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int num_islands = 0;
        int r = grid.size();
        int c = grid[0].size();

        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (grid[i][j] == '1')
                {
                    num_islands++;
                    DFS(grid, i, j);
                }
            }
        }

        return num_islands;
    }

    void DFS(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] != '1')
            return;

        grid[i][j] = '0';
        DFS(grid, i, j - 1);
        DFS(grid, i, j + 1);
        DFS(grid, i - 1, j);
        DFS(grid, i + 1, j);
    }
};