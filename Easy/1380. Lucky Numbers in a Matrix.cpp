// https://leetcode.com/problems/lucky-numbers-in-a-matrix/

class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        vector<int> result;
        vector<int> minRow;

        for (vector<int> row : matrix)
        {
            int min = INT_MAX;

            for (int num : row)
                if (min > num)
                    min = num;

            minRow.push_back(min);
        }

        for (int j = 0; j < matrix[0].size(); ++j)
        {
            int max = INT_MIN;
            int position = 0;

            for (int i = 0; i < matrix.size(); i++)
            {
                if (matrix[i][j] > max)
                {
                    max = matrix[i][j];
                    position = i;
                }
            }

            if (max == minRow[position])
                result.push_back(max);
        }

        return result;
    }
};