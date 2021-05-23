// https://leetcode.com/problems/minimum-falling-path-sum/

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int result = INT_MAX;

        for (int i = matrix.size() - 2; i >= 0; --i)
            for (int j = matrix[0].size() - 1; j >= 0; --j)
                matrix[i][j] += min({getValue(matrix, i + 1, j), getValue(matrix, i + 1, j - 1), getValue(matrix, i + 1, j + 1)});

        for (int j = 0; j < matrix[0].size(); ++j)
            result = min(result, matrix[0][j]);

        return result;
    }

    int getValue(vector<vector<int>> &matrix, int i, int j)
    {
        if (j < 0 || j >= matrix[0].size())
            return 1e+8;

        return matrix[i][j];
    }
};