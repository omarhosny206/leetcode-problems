class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        for (int &num : A)
            num = num * num;
        quickSort(A, 0, A.size() - 1);
        return A;
    }

    void quickSort(vector<int> &nums, int left, int right)
    {
        if (left < right)
        {
            int pivotIndex = partition(nums, left, right);
            quickSort(nums, left, pivotIndex - 1);
            quickSort(nums, pivotIndex, right);
        }
    }

    int partition(vector<int> &nums, int left, int right)
    {
        int pivotIndex = left + (right - left) / 2;
        int pivotValue = nums[pivotIndex];
        int i = left, j = right;
        int temp;
        while (i <= j)
        {
            while (nums[i] < pivotValue)
            {
                i++;
            }
            while (nums[j] > pivotValue)
            {
                j--;
            }
            if (i <= j)
            {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
            }
        }
        return i;
    }
};