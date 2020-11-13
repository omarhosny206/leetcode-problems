// https://leetcode.com/problems/triangle/

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int rows = triangle.size();
        int max_col = triangle[rows - 1].size();

        vector<int> dp(max_col + 1);

        for (int i = max_col - 1; i >= 0; --i)
            for (int j = 0; j <= i; ++j)
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];

        return dp[0];
    }
};