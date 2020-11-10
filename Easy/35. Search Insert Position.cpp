// https://leetcode.com/problems/search-insert-position/

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int position = binarySearch(nums, target, 0, nums.size() - 1);
        if (position == -1)
        {
            int i = 0;
            while (i < nums.size() && nums[i] < target)
                i++;
            position = i;
        }

        return position;
    }

    int binarySearch(vector<int> &nums, int target, int left, int right)
    {
        if (left > right)
            return -1;
        int middle = left + (right - middle) / 2;

        if (nums[middle] == target)
            return middle;
        else if (nums[middle] > target)
            return binarySearch(nums, target, left, middle - 1);
        else
            return binarySearch(nums, target, middle + 1, right);
    }
};