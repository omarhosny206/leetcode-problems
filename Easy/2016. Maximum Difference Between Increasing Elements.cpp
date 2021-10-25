// https://leetcode.com/problems/maximum-difference-between-increasing-elements/

class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int result = 0;
        int minNumber = INT_MAX;

        for (int i = 0; i < nums.size(); ++i)
        {
            result = max(result, nums[i] - minNumber);
            minNumber = min(minNumber, nums[i]);
        }

        return result == 0 ? -1 : result;
    }
};