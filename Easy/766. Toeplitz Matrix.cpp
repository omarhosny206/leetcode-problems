// https://leetcode.com/problems/toeplitz-matrix/

class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size(); ++i)
            if (!check(matrix, matrix[i][0], i, 0))
                return false;

        for (int j = 0; j < matrix[0].size(); ++j)
            if (!check(matrix, matrix[0][j], 0, j))
                return false;

        return true;
    }

    bool check(vector<vector<int>> &matrix, int value, int i, int j)
    {
        while (isValidPosition(matrix, i, j))
        {
            if (value != matrix[i][j])
                return false;

            i++;
            j++;
        }

        return true;
    }

    bool isValidPosition(vector<vector<int>> &matrix, int i, int j)
    {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size())
            return false;

        return true;
    }
};