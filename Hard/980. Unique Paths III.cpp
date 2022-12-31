
class Solution
{
    int result = 0;
    int row;
    int column;
    int counter = -1;
    int numEmpty = 0;

public:
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == 0)
                    numEmpty++;

                if (grid[i][j] == 1)
                {
                    row = i;
                    column = j;
                }
            }
        }

        dfs(grid, row, column);
        return result;
    }

    void dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (i >= grid.size() || i < 0 || j >= grid[i].size() || j < 0 || grid[i][j] == 3 || grid[i][j] == -1)
            return;

        if (grid[i][j] == 2)
        {
            if (counter == numEmpty)
                result++;

            return;
        }

        counter++;

        int temp = grid[i][j];
        grid[i][j] = 3;
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
        grid[i][j] = temp;

        counter--;
    }
};