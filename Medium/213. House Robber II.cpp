// https://leetcode.com/problems/house-robber-ii/

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);

        int first = robHelper(nums, 0, nums.size() - 2);
        int second = robHelper(nums, 1, nums.size() - 1);
        return max(first, second);
    }

    int robHelper(vector<int> &nums, int start, int end)
    {
        vector<int> dp(end - start + 1);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);

        for (int i = start + 2; i <= end; ++i)
            dp[i - start] = max(nums[i] + dp[i - start - 2], dp[i - start - 1]);

        return dp[end - start];
    }
};