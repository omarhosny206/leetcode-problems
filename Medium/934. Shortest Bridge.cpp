// https://leetcode.com/problems/shortest-bridge/

class Solution
{
    queue<pair<int, int>> graph;
    vector<vector<bool>> visited;

public:
    int shortestBridge(vector<vector<int>> &grid)
    {
        visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size()));

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    dfs(grid, i, j);
                    break;
                }
            }

            if (graph.size() > 0)
                break;
        }

        return bfs(grid);
    }

    int bfs(vector<vector<int>> &grid)
    {
        int result = 0;
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!graph.empty())
        {
            int size = graph.size();

            for (int i = 0; i < size; ++i)
            {
                pair<int, int> nodePosition = graph.front();
                graph.pop();

                for (vector<int> &direction : directions)
                {
                    int row = direction[0] + nodePosition.first;
                    int column = direction[1] + nodePosition.second;

                    if (isValidPosition(grid, row, column) && visited[row][column] == false)
                    {
                        if (grid[row][column] == 1)
                            return result;

                        graph.push({row, column});
                        visited[row][column] = true;
                    }
                }
            }

            result++;
        }

        return -1;
    }

    void dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (!isValidPosition(grid, i, j) || grid[i][j] == 0 || visited[i][j] == true)
            return;

        graph.push({i, j});
        visited[i][j] = true;

        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    bool isValidPosition(vector<vector<int>> &grid, int i, int j)
    {
        if (i >= grid.size() || i < 0 || j >= grid[i].size() || j < 0)
            return false;

        return true;
    }
};