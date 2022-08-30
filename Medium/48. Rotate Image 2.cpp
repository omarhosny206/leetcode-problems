// https://leetcode.com/problems/rotate-image/

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size(); ++i)
            reverse(matrix[i]);

        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size() - i; ++j)
            {
                int row = matrix.size() - j - 1;
                int column = matrix.size() - i - 1;
                int temp = matrix[i][j];
                matrix[i][j] = matrix[row][column];
                matrix[row][column] = temp;
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