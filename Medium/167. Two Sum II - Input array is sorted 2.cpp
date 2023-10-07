// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            int index = binarySearch(nums, target - nums[i], i + 1, nums.size() - 1);
            if (index != -1)
                return {i + 1, index + 1};
        }

        return {};
    }

    int binarySearch(vector<int> &nums, int target, int left, int right)
    {
        if (left > right)
            return -1;

        int middle = left + (right - left) / 2;

        if (nums[middle] == target)
            return middle;

        if (nums[middle] < target)
            return binarySearch(nums, target, middle + 1, right);

        return binarySearch(nums, target, left, middle - 1);
    }
};