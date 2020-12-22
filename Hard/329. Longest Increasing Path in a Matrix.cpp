// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

class Solution
{
public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0)
            return 0;

        int answer = 0;
        vector<vector<int>> DP(matrix.size(), vector<int>(matrix[0].size(), -1));

        for (int i = 0; i < matrix.size(); ++i)
            for (int j = 0; j < matrix[i].size(); ++j)
                answer = max(answer, DFS(matrix, DP, i, j, INT_MIN));

        return answer;
    }

    int DFS(vector<vector<int>> &matrix, vector<vector<int>> &DP, int i, int j, int last_val)
    {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[i].size() || matrix[i][j] <= last_val)
            return 0;

        if (DP[i][j] != -1)
            return DP[i][j];

        DP[i][j] = 1 + max({DFS(matrix, DP, i + 1, j, matrix[i][j]),
                            DFS(matrix, DP, i - 1, j, matrix[i][j]),
                            DFS(matrix, DP, i, j + 1, matrix[i][j]),
                            DFS(matrix, DP, i, j - 1, matrix[i][j])});

        return DP[i][j];
    }
};