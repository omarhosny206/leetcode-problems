// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int counter = 0;

        for (int i = 0; i < grid.size(); ++i)
        {
            int j = grid[i].size() - 1;

            while (j >= 0 && grid[i][j--] < 0)
                counter++;
        }

        return counter;
    }
};