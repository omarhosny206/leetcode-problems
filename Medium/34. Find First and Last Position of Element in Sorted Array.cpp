// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return {-1, -1};
        int leftIndex = leftBinarySearch(nums, target);
        int rightIndex = rightBinarySearch(nums, target);

        return {leftIndex, rightIndex};
    }

    int leftBinarySearch(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high)
        {
            int middle = low + (high - low) / 2;
            if (nums[middle] == target && (middle == 0 || (middle > 0 && nums[middle - 1] != target)))
                return middle;
            else if (nums[middle] >= target)
                high = middle - 1;
            else
                low = middle + 1;
        }

        return -1;
    }

    int rightBinarySearch(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high)
        {
            int middle = low + (high - low) / 2;
            if (nums[middle] == target && (middle == nums.size() - 1 || (middle < nums.size() - 1 && nums[middle + 1] != target)))
                return middle;
            else if (nums[middle] <= target)
                low = middle + 1;
            else
                high = middle - 1;
        }

        return -1;
    }
};