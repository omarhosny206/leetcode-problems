// https://leetcode.com/problems/minimum-falling-path-sum/

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int result = INT_MAX;
        vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size(), INT_MAX));

        for (int j = 0; j < matrix[0].size(); ++j)
            result = min(result, dfs(matrix, memo, 0, j));

        return result;
    }

    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &memo, int i, int j)
    {
        if (i == matrix.size())
            return 0;

        if (i >= matrix.size() || i < 0 || j >= matrix[i].size() || j < 0)
            return 1e8;

        if (memo[i][j] != INT_MAX)
            return memo[i][j];

        memo[i][j] = min({memo[i][j],
                          matrix[i][j] + dfs(matrix, memo, i + 1, j),
                          matrix[i][j] + dfs(matrix, memo, i + 1, j - 1),
                          matrix[i][j] + dfs(matrix, memo, i + 1, j + 1)});

        return memo[i][j];
    }
};