// https://leetcode.com/problems/rotate-image/

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        transpose(matrix);

        for (vector<int> &row : matrix)
            reverse(row);
    }

    void transpose(vector<vector<int>> &matrix)
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

    void reverse(vector<int> &row)
    {
        int i = 0;
        int j = row.size() - 1;

        while (i < j)
        {
            int temp = row[i];
            row[i++] = row[j];
            row[j--] = temp;
        }
    }
};