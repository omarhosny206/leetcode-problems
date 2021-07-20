// https://leetcode.com/problems/concatenation-of-array/

class Solution
{
public:
    vector<int> getConcatenation(vector<int> &nums)
    {
        vector<int> result(nums.size() * 2);
        int i = 0;

        while (i < nums.size())
        {
            result[i] = nums[i % nums.size()];
            result[i + nums.size()] = nums[i % nums.size()];
            i++;
        }

        return result;
    }
};