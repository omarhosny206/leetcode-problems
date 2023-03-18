
class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int result = 0;
        unordered_map<int, int> size;
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int id = 2;

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    int counter = 0;
                    dfs(grid, i, j, id, counter);
                    size[id] = counter;
                    id++;
                }
            }
        }

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == 0)
                {
                    int currentSize = 0;
                    unordered_set<int> islands;

                    for (vector<int> &direction : directions)
                    {
                        int row = i + direction[0];
                        int column = j + direction[1];

                        if (row < grid.size() && row >= 0 && column < grid[row].size() && column >= 0 && grid[row][column] != 0)
                        {
                            int currentId = grid[row][column];

                            if (islands.find(currentId) == islands.end())
                                currentSize += size[currentId];

                            islands.insert(currentId);
                        }
                    }

                    result = max(result, currentSize + 1);
                }
            }
        }

        return result == 0 ? grid.size() * grid.size() : result;
    }

    void dfs(vector<vector<int>> &grid, int i, int j, int id, int &counter)
    {
        if (i >= grid.size() || i < 0 || j >= grid[i].size() || j < 0 || grid[i][j] != 1)
            return;

        counter++;
        grid[i][j] = id;

        dfs(grid, i + 1, j, id, counter);
        dfs(grid, i - 1, j, id, counter);
        dfs(grid, i, j + 1, id, counter);
        dfs(grid, i, j - 1, id, counter);
    }
};