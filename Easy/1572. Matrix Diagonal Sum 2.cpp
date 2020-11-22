// https://leetcode.com/problems/matrix-diagonal-sum/

class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {

        int sum = 0;

        for (int i = 0, j = mat.size() - 1; i < mat.size() && j >= 0; ++i, --j)
            sum += mat[i][j] + mat[i][i];

        if (mat.size() % 2 != 0)
            sum -= mat[mat.size() / 2][mat.size() / 2];

        return sum;
    }
};