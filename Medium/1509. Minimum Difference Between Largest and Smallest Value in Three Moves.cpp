// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/

class Solution
{
public:
    int minDifference(vector<int> &nums)
    {
        if (nums.size() <= 4)
            return 0;

        int minDifference = INT_MAX;
        sort(nums.begin(), nums.end());

        for (int i = 0; i <= 3; ++i)
            minDifference = min(minDifference, nums[nums.size() - i - 1] - nums[3 - i]);

        return minDifference;
    }
};