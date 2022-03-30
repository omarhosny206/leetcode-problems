// https://leetcode.com/problems/search-a-2d-matrix/

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = getRow(matrix, target);
        return binarySearch(matrix, row, target);
    }

    bool binarySearch(vector<vector<int>> &matrix, int row, int target)
    {
        int left = 0;
        int right = matrix[row].size() - 1;

        while (left <= right)
        {
            int middle = left + (right - left) / 2;

            if (matrix[row][middle] == target)
                return true;

            if (matrix[row][middle] > target)
                right = middle - 1;

            else
                left = middle + 1;
        }

        return false;
    }

    int getRow(vector<vector<int>> &matrix, int target)
    {
        int top = 0;
        int bottom = matrix.size() - 1;

        while (top <= bottom)
        {
            int middle = top + (bottom - top) / 2;

            if (matrix[middle][0] <= target && matrix[middle][matrix[middle].size() - 1] >= target)
                return middle;

            if (matrix[middle][0] > target)
                bottom = middle - 1;

            else
                top = middle + 1;
        }

        return 0;
    }
};