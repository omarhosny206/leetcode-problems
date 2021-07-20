// https://leetcode.com/problems/minimum-distance-to-the-target-element/

class Solution
{
public:
    int getMinDistance(vector<int> &nums, int target, int start)
    {
        int result = getMinimumDistance(nums, target, start);
        return result;
    }

    int getMinimumDistance(vector<int> &nums, int target, int start)
    {
        int result = INT_MAX;

        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] == target)
                result = min(result, abs(start - i));

        return result;
    }
};