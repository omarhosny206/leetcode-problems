// https://leetcode.com/problems/search-a-2d-matrix/

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = getRowByBinarySearch(matrix, 0, matrix.size() - 1, target);
        return (row == -1) ? false : binarySearch(matrix, row, 0, matrix[0].size() - 1, target);
    }

    bool binarySearch(vector<vector<int>> &matrix, int row, int left, int right, int target)
    {
        if (left > right)
            return false;

        int middle = left + (right - left) / 2;

        if (matrix[row][middle] == target)
            return true;

        if (matrix[row][middle] > target)
            return binarySearch(matrix, row, left, middle - 1, target);

        return binarySearch(matrix, row, middle + 1, right, target);
    }

    int getRowByBinarySearch(vector<vector<int>> &matrix, int top, int bottom, int target)
    {
        if (top > bottom)
            return -1;

        int middle = top + (bottom - top) / 2;

        if (matrix[middle][0] <= target && matrix[middle][matrix[middle].size() - 1] >= target)
            return middle;

        if (matrix[middle][0] > target)
            return getRowByBinarySearch(matrix, top, middle - 1, target);

        return getRowByBinarySearch(matrix, middle + 1, bottom, target);
    }
};