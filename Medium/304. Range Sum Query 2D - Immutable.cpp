// https://leetcode.com/problems/range-sum-query-2d-immutable/

class NumMatrix
{
    vector<vector<int>> DP;

public:
    NumMatrix(vector<vector<int>> &matrix)
    {

        if (matrix.size() == 0 || matrix[0].size() == 0)
            return;

        DP = vector<vector<int>>(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));

        for (int r = 0; r < matrix.size(); r++)
            for (int c = 0; c < matrix[0].size(); c++)
                DP[r + 1][c + 1] = DP[r + 1][c] + DP[r][c + 1] + matrix[r][c] - DP[r][c];
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return DP[row2 + 1][col2 + 1] - DP[row1][col2 + 1] - DP[row2 + 1][col1] + DP[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */