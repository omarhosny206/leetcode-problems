// https://leetcode.com/problems/delete-greatest-value-in-each-row/

class Solution
{
public:
    int deleteGreatestValue(vector<vector<int>> &grid)
    {
        int result = 0;
        unordered_map<int, priority_queue<int>> values;

        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[i].size(); ++j)
                values[i].push(grid[i][j]);

        for (int j = 0; j < grid[0].size(); ++j)
        {
            int rowMaxValue = INT_MIN;

            for (int i = 0; i < grid.size(); ++i)
            {
                int value = values[i].top();
                values[i].pop();

                rowMaxValue = max(rowMaxValue, value);
            }

            result += rowMaxValue;
        }

        return result;
    }
};