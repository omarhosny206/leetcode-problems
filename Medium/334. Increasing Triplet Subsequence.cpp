// https://leetcode.com/problems/increasing-triplet-subsequence/

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > firstMin && nums[i] > secondMin)
                return true;

            if (nums[i] <= firstMin)
                firstMin = nums[i];

            else if (nums[i] <= secondMin)
                secondMin = nums[i];
        }

        return false;
    }
};