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

        while (top <= bottom && left <= right)
        {
            for (int j = left; j <= right; ++j)
                result.push_back(matrix[top][j]);

            top++;

            if (top > bottom)
                break;

            for (int i = top; i <= bottom; ++i)
                result.push_back(matrix[i][right]);

            right--;

            if (right < left)
                break;

            for (int j = right; j >= left; --j)
                result.push_back(matrix[bottom][j]);

            bottom--;

            for (int i = bottom; i >= top; --i)
                result.push_back(matrix[i][left]);

            left++;
        }

        return result;
    }
};