// https://leetcode.com/problems/rotate-image/

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int size = matrix.size();

        for (int i = 0; i < (size + 1) / 2; ++i)
        {
            for (int j = 0; j < size / 2; ++j)
            {
                int temp = matrix[size - 1 - j][i];
                matrix[size - 1 - j][i] = matrix[size - 1 - i][size - 1 - j];
                matrix[size - 1 - i][size - 1 - j] = matrix[j][size - 1 - i];
                matrix[j][size - 1 - i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
};