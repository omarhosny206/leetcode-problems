
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        return binarySearch(nums, target, left, right);
    }

    int binarySearch(vector<int> &nums, int target, int left, int right)
    {
        int result = -1;

        if (left > right)
            return -1;

        int middle = left + (right - left) / 2;

        if (nums[middle] == target)
            return middle;

        else if (nums[middle] > target)
            result = binarySearch(nums, target, left, middle - 1);

        else
            result = binarySearch(nums, target, middle + 1, right);

        return result;
    }
};