// https://leetcode.com/problems/spiral-matrix/

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> result;

        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = m - 1;

        while (result.size() < n * m)
        {
            for (int j = left; j <= right && result.size() < n * m; ++j)
                result.push_back(matrix[top][j]);

            top++;

            for (int i = top; i <= bottom && result.size() < n * m; ++i)
                result.push_back(matrix[i][right]);

            right--;

            for (int j = right; j >= left && result.size() < n * m; --j)
                result.push_back(matrix[bottom][j]);

            bottom--;

            for (int i = bottom; i >= top && result.size() < n * m; --i)
                result.push_back(matrix[i][left]);

            left++;
        }

        return result;
    }
};