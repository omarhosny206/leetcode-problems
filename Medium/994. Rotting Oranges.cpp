// https://leetcode.com/problems/rotting-oranges/

class Solution
{
    int result = 0;

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> cells;

        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[i].size(); ++j)
                if (grid[i][j] == 2)
                    cells.push({i, j});

        BFS(grid, cells);

        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[i].size(); ++j)
                if (grid[i][j] == 1)
                    return -1;

        return result;
    }

    void BFS(vector<vector<int>> &grid, queue<pair<int, int>> &cells)
    {
        int directions[] = {-1, 0, 1, 0, -1};
        int numCells = cells.size();

        while (numCells > 0)
        {
            while (numCells--)
            {
                int i = cells.front().first;
                int j = cells.front().second;
                cells.pop();

                for (int k = 0; k < 4; ++k)
                {
                    if (checkBoundaries(grid, i + directions[k], j + directions[k + 1]))
                    {
                        grid[i + directions[k]][j + directions[k + 1]] = 2;
                        cells.push({i + directions[k], j + directions[k + 1]});
                    }
                }
            }

            numCells = cells.size();

            if (numCells > 0)
                result++;
        }
    }

    bool checkBoundaries(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] != 1)
            return false;

        return true;
    }
};