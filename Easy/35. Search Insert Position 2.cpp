class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }

    int binarySearch(vector<int> &nums, int target, int left, int right)
    {
        while (left <= right)
        {
            int middle = left + (right - left) / 2;

            if (nums[middle] == target)
                return middle;

            if (nums[middle] < target)
                left = middle + 1;

            else
                right = middle - 1;
        }

        return left;
    }
};