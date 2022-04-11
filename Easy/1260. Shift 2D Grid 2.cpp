
class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        vector<vector<int>> result(grid.size(), vector<int>(grid[0].size()));
        vector<int> nums;

        int position = 0;

        for (vector<int> &row : grid)
            for (int &num : row)
                nums.push_back(num);

        while (k--)
        {
            int num = nums.back();
            nums.pop_back();
            nums.insert(nums.begin(), num);
        }

        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[i].size(); ++j)
                result[i][j] = nums[position++];

        return result;
    }
};