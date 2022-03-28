// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int i = 0;

        while (i < nums.size() - 1 && nums[i] <= nums[i + 1])
            i++;

        return binarySearch(nums, 0, i, target) || binarySearch(nums, i + 1, nums.size() - 1, target);
    }

    bool binarySearch(vector<int> &nums, int left, int right, int target)
    {

        if (left >= nums.size() || right >= nums.size())
            return false;

        while (left <= right)
        {
            int middle = left + (right - left) / 2;

            if (nums[middle] == target)
                return true;

            if (nums[middle] > target)
                right = middle - 1;

            else
                left = middle + 1;
        }

        return false;
    }
};