// https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), compare);

        for (int i = 0; i < nums.size(); ++i)
            nums[i] *= nums[i];

        return nums;
    }

    static bool compare(int &first, int &second)
    {
        return (first * first) < (second * second);
    }
};