// https://leetcode.com/problems/reshape-the-matrix/

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
    {
        vector<vector<int>> result(r, vector<int>(c));

        if (nums.size() == 0 || r * c != nums.size() * nums[0].size())
            return nums;

        queue<int> data;
        for (int i = 0; i < nums.size(); i++)
            for (int j = 0; j < nums[0].size(); j++)
                data.push(nums[i][j]);

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                result[i][j] = data.front();
                data.pop();
            }
        }

        return result;
    }
};