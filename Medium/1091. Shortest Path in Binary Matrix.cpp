// https://leetcode.com/problems/shortest-path-in-binary-matrix/

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        if (grid[0][0] == 1 || grid[grid.size() - 1][grid[0].size() - 1] == 1)
            return -1;

        if (grid.size() == 1)
            return 1;

        int result = 1;
        queue<pair<int, int>> nodes;
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};

        nodes.push({0, 0});
        grid[0][0] = 2;

        while (!nodes.empty())
        {
            result++;
            int size = nodes.size();

            for (int i = 0; i < size; ++i)
            {
                pair<int, int> node = nodes.front();
                nodes.pop();

                int row = node.first;
                int column = node.second;

                for (vector<int> &direction : directions)
                {
                    int newRow = row + direction[0];
                    int newColumn = column + direction[1];

                    if (!isValidPosition(grid, newRow, newColumn))
                        continue;

                    if (newRow == grid.size() - 1 && newColumn == grid[newRow].size() - 1 && grid[newRow][newColumn] == 0)
                        return result;

                    if (grid[newRow][newColumn] == 0)
                    {
                        nodes.push({newRow, newColumn});
                        grid[newRow][newColumn] = 2;
                    }
                }
            }
        }

        return -1;
    }

    bool isValidPosition(vector<vector<int>> &grid, int i, int j)
    {
        if (i >= grid.size() || i < 0 || j >= grid[i].size() || j < 0)
            return false;

        return true;
    }
};