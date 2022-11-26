// https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/

class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {
        vector<vector<int>> result(grid.size(), vector<int>(grid[0].size()));
        unordered_map<int, int> row;
        unordered_map<int, int> column;

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == 0)
                {
                    row[i]--;
                    column[j]--;
                }

                else
                {
                    row[i]++;
                    column[j]++;
                }
            }
        }

        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[i].size(); ++j)
                result[i][j] = row[i] + column[j];

        return result;
    }
};