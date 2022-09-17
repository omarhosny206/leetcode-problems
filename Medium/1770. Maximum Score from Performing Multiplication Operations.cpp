// https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/

class Solution
{
public:
    vector<vector<int>> dp;

    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        int n = nums.size(), m = multipliers.size();
        dp.resize(m + 1, vector<int>(m + 1, INT_MIN));

        return solve(nums, multipliers, 0, n, 0);
    }

    int solve(vector<int> &nums, vector<int> &multipliers, int i, int n, int j)
    {
        if (j == multipliers.size())
            return 0;

        if (dp[i][j] != INT_MIN)
            return dp[i][j];

        int left = solve(nums, multipliers, i + 1, n, j + 1) + (nums[i] * multipliers[j]);
        int right = solve(nums, multipliers, i, n, j + 1) + (nums[(n - 1) - (j - i)] * multipliers[j]);

        dp[i][j] = max(left, right);
        return dp[i][j];
    }
};