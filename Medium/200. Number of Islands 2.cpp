// https://leetcode.com/problems/number-of-islands/

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int result = 0;

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == '1')
                {
                    result++;
                    bfs(grid, i, j);
                }
            }
        }

        return result;
    }

    void bfs(vector<vector<char>> &grid, int i, int j)
    {
        queue<pair<int, int>> nodes;
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        nodes.push({i, j});
        grid[i][j] = '0';

        while (!nodes.empty())
        {
            int size = nodes.size();

            for (int k = 0; k < size; ++k)
            {
                pair<int, int> current = nodes.front();
                nodes.pop();

                for (auto &direction : directions)
                {
                    int row = current.first + direction[0];
                    int column = current.second + direction[1];

                    if (isValidPosition(grid, row, column))
                    {
                        nodes.push({row, column});
                        grid[row][column] = '0';
                    }
                }
            }
        }
    }

    bool isValidPosition(vector<vector<char>> &grid, int i, int j)
    {
        if (i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0 || grid[i][j] == '0')
            return false;

        return true;
    }
};