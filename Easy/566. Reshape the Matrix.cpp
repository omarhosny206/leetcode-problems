// https://leetcode.com/problems/reshape-the-matrix/

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
    {
        vector<vector<int>> result(r, vector<int>(c));

        if (nums.size() == 0 || r * c != nums.size() * nums[0].size())
            return nums;

        int row = 0;
        int column = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums[0].size(); j++)
            {
                result[row][column++] = nums[i][j];

                if (column == c)
                {
                    column = 0;
                    row++;
                }
            }
        }

        return result;
    }
};