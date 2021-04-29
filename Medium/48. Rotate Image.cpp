// https://leetcode.com/problems/rotate-image/

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        Transpose(matrix);

        for (int i = 0; i < matrix.size(); i++)
            Reverse(matrix, i);
    }

    void Transpose(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = i; j < matrix.size(); j++)
            {
                int temp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }

    void Reverse(vector<vector<int>> &matrix, int row)
    {
        int i = 0;
        int j = matrix[i].size() - 1;

        while (i < j)
        {
            int temp = matrix[row][i];
            matrix[row][i++] = matrix[row][j];
            matrix[row][j--] = temp;
        }
    }
};