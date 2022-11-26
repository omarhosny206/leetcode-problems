// https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/

class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {
        vector<vector<int>> result(grid.size(), vector<int>(grid[0].size()));
        unordered_map<int, int> rowZeros;
        unordered_map<int, int> columnZeros;
        unordered_map<int, int> rowOnes;
        unordered_map<int, int> columnOnes;

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == 0)
                {
                    rowZeros[i]++;
                    columnZeros[j]++;
                }

                else
                {
                    rowOnes[i]++;
                    columnOnes[j]++;
                }
            }
        }

        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[i].size(); ++j)
                result[i][j] = rowOnes[i] + columnOnes[j] - rowZeros[i] - columnZeros[j];

        return result;
    }
};