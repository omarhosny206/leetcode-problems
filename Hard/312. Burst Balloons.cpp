// https://leetcode.com/problems/burst-balloons/

class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));

        return dfs(nums, dp, 1, nums.size() - 2);
    }

    int dfs(vector<int> &nums, vector<vector<int>> &dp, int i, int j)
    {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        for (int k = i; k <= j; ++k)
        {
            int current = nums[i - 1] * nums[j + 1] * nums[k];
            dp[i][j] = max(dp[i][j], dfs(nums, dp, i, k - 1) + current + dfs(nums, dp, k + 1, j));
        }

        return dp[i][j];
    }
};