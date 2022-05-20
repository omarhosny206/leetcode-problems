// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

class Solution
{
public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int result = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));

        for (int i = 0; i < matrix.size(); ++i)
            for (int j = 0; j < matrix[i].size(); ++j)
                result = max(result, dfs(matrix, dp, i, j, INT_MIN));

        return result;
    }

    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j, int last_val)
    {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[i].size() || matrix[i][j] <= last_val)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        dp[i][j] = 1 + max({dfs(matrix, dp, i + 1, j, matrix[i][j]),
                            dfs(matrix, dp, i - 1, j, matrix[i][j]),
                            dfs(matrix, dp, i, j + 1, matrix[i][j]),
                            dfs(matrix, dp, i, j - 1, matrix[i][j])});

        return dp[i][j];
    }
};