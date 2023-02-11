// https://leetcode.com/problems/as-far-from-land-as-possible/

class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        return bfs(grid);
    }

    int bfs(vector<vector<int>> &grid)
    {
        int result = INT_MIN;
        queue<pair<int, int>> nodes;
        vector<vector<int>> values(grid.size(), vector<int>(grid.size(), -1));
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    nodes.push({i, j});
                    values[i][j] = 0;
                }
            }
        }

        while (!nodes.empty())
        {
            int size = nodes.size();

            for (int i = 0; i < size; ++i)
            {
                pair<int, int> current = nodes.front();
                nodes.pop();

                for (vector<int> &direction : directions)
                {
                    int row = current.first + direction[0];
                    int column = current.second + direction[1];

                    if (isValidCell(grid, values, row, column))
                    {
                        nodes.push({row, column});
                        values[row][column] = values[current.first][current.second] + 1;
                    }
                }
            }
        }

        for (int i = 0; i < values.size(); ++i)
            for (int j = 0; j < values[i].size(); ++j)
                if (values[i][j] != 0)
                    result = max(result, values[i][j]);

        return result == INT_MIN ? -1 : result;
    }

    bool isValidCell(vector<vector<int>> &grid, vector<vector<int>> &values, int i, int j)
    {
        if (i >= grid.size() || i < 0 || j >= grid[i].size() || j < 0 || values[i][j] != -1)
            return false;

        return true;
    }
};