// https://leetcode.com/problems/spiral-matrix-ii/

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> result(n, vector<int>(n));

        int currentNumber = 1;
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;

        while (top <= bottom && left <= right)
        {
            for (int j = left; j <= right; ++j)
                result[top][j] = currentNumber++;

            top++;

            for (int i = top; i <= bottom; ++i)
                result[i][right] = currentNumber++;

            right--;

            for (int j = right; j >= left; --j)
                result[bottom][j] = currentNumber++;

            bottom--;

            for (int i = bottom; i >= top; --i)
                result[i][left] = currentNumber++;

            left++;
        }

        return result;
    }
};