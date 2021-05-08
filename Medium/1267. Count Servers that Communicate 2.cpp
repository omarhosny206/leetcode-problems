// https://leetcode.com/problems/count-servers-that-communicate/

class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        int result = 0;

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    int count = 0;
                    DFS(grid, count, i, j);
                    result += (count > 1) ? count : 0;
                }
            }
        }

        return result;
    }

    void DFS(vector<vector<int>> &grid, int &count, int i, int j)
    {
        if (grid[i][j] == 1)
        {
            count++;
            grid[i][j] = 0;

            for (int r = 0; r < grid.size(); ++r)
                DFS(grid, count, r, j);

            for (int c = 0; c < grid[i].size(); ++c)
                DFS(grid, count, i, c);
        }
    }
};