class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int low = 0;
        int high = matrix.size() - 1;

        while (low <= high)
        {
            int row = low + (high - low) / 2;
            bool check = BinarySearch(matrix[row], target);

            if (matrix[row][0] <= target && matrix[row][matrix[row].size() - 1] >= target)
                return BinarySearch(matrix[row], target);

            else if (matrix[row][0] > target)
                high = row - 1;

            else
                low = row + 1;
        }

        return false;
    }

    bool BinarySearch(vector<int> &row, int target)
    {
        int low = 0;
        int high = row.size() - 1;

        while (low <= high)
        {
            int middle = low + (high - low) / 2;
            if (row[middle] == target)
                return true;
            if (row[middle] > target)
                high = middle - 1;
            else
                low = middle + 1;
        }

        return false;
    }
};