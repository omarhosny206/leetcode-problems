// https://leetcode.com/problems/count-servers-that-communicate/

class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        int result = 0;

        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[i].size(); ++j)
                if (grid[i][j] == 1 && isConnected(grid, i, j))
                    result++;

        return result;
    }

    bool isConnected(vector<vector<int>> &grid, int i, int j)
    {
        for (int k = 0; k < grid.size(); ++k)
            if (k != i && grid[k][j] == 1)
                return true;

        for (int k = 0; k < grid[i].size(); ++k)
            if (k != j && grid[i][k] == 1)
                return true;

        return false;
    }
};