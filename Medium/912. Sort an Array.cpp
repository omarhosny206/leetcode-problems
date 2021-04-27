// https://leetcode.com/problems/sort-an-array/

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quickSort(vector<int> &nums, int left, int right)
    {
        if (left >= right)
            return;

        int pivotIndex = Partition(nums, left, right);
        quickSort(nums, left, pivotIndex - 1);
        quickSort(nums, pivotIndex, right);
    }

    int Partition(vector<int> &nums, int left, int right)
    {
        int pivotIndex = left + (right - left) / 2;
        int pivotValue = nums[pivotIndex];
        int i = left, j = right;
        int temp;

        while (i <= j)
        {
            while (nums[i] < pivotValue)
                i++;

            while (nums[j] > pivotValue)
                j--;

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