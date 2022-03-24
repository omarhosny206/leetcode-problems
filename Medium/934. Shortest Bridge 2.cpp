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
                    collectSourcesBFS(grid, i, j);
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

    void collectSourcesBFS(vector<vector<int>> &grid, int i, int j)
    {
        queue<pair<int, int>> nodes;
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        nodes.push({i, j});
        graph.push({i, j});
        visited[i][j] = true;

        while (!nodes.empty())
        {
            int size = nodes.size();

            for (int i = 0; i < size; ++i)
            {
                pair<int, int> nodePosition = nodes.front();
                nodes.pop();

                for (vector<int> &direction : directions)
                {
                    int row = direction[0] + nodePosition.first;
                    int column = direction[1] + nodePosition.second;

                    if (isValidPosition(grid, row, column) && grid[row][column] == 1 && visited[row][column] == false)
                    {
                        nodes.push({row, column});
                        graph.push({row, column});
                        visited[row][column] = true;
                    }
                }
            }
        }
    }

    bool isValidPosition(vector<vector<int>> &grid, int i, int j)
    {
        if (i >= grid.size() || i < 0 || j >= grid[i].size() || j < 0)
            return false;

        return true;
    }
};