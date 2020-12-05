// https://leetcode.com/problems/transpose-matrix/

class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &A)
    {
        int rows = A.size();
        int columns = A[0].size();

        vector<vector<int>> result(columns, vector<int>(rows, 0));
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < columns; ++j)
                result[j][i] = A[i][j];

        return result;
    }
};