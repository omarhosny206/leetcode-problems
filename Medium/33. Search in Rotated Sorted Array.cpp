// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int pivot = pivotBinarySearch(nums, 0, nums.size() - 1);
        int result;

        if (target <= nums[nums.size() - 1])
            result = binarySearch(nums, target, pivot, nums.size() - 1);

        else
            result = binarySearch(nums, target, 0, pivot - 1);

        return result;
    }

    int binarySearch(vector<int> &nums, int target, int start, int end)
    {
        if (start <= end)
        {
            int middle = start + (end - start) / 2;

            if (nums[middle] == target)
                return middle;

            else if (nums[middle] > target)
                return binarySearch(nums, target, start, middle - 1);

            else
                return binarySearch(nums, target, middle + 1, end);
        }
        return -1;
    }

    int pivotBinarySearch(vector<int> &nums, int start, int end)
    {
        if (start < end)
        {
            int middle = start + (end - start) / 2;

            if (nums[middle] <= nums[end])
                return pivotBinarySearch(nums, start, middle);

            else
                return pivotBinarySearch(nums, middle + 1, end);
        }
        return end;
    }
};