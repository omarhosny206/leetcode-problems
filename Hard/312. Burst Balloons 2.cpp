// https://leetcode.com/problems/burst-balloons/

class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));

        for (int size = 1; size <= nums.size() - 2; ++size)
        {
            for (int i = 1, j = i + size - 1; j < nums.size() - 1; ++j, ++i)
            {
                for (int k = i; k <= j; ++k)
                {
                    int cur = nums[i - 1] * nums[j + 1] * nums[k];
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + cur + dp[k + 1][j]);
                }
            }
        }

        return dp[1][nums.size() - 2];
    }
};