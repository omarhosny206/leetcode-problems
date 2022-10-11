// https://leetcode.com/problems/increasing-triplet-subsequence/

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        vector<int> rightMax(nums.size());
        vector<int> leftMin(nums.size());
        int maxValue = INT_MIN;
        int minValue = INT_MAX;

        int left = 0;
        int right = nums.size() - 1;

        for (int i = 0; i < nums.size(); ++i)
        {
            maxValue = max(maxValue, nums[right - i]);
            rightMax[right - i] = maxValue;

            minValue = min(minValue, nums[left + i]);
            leftMin[left + i] = minValue;
        }

        for (int i = 1; i < nums.size() - 1; ++i)
            if (nums[i] > leftMin[i] && nums[i] < rightMax[i])
                return true;

        return false;
    }
};