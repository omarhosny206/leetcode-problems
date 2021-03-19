// https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];

        if (nums[0] != nums[1])
            return nums[0];

        if (nums[nums.size() - 1] != nums[nums.size() - 2])
            return nums[nums.size() - 1];

        return binarySearch(nums);
    }

    int binarySearch(vector<int> &nums)
    {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high)
        {
            int middle = low + (high - low) / 2;

            if (nums[middle] != nums[middle - 1] && nums[middle] != nums[middle + 1])
                return nums[middle];

            else if (middle % 2 == 0 && nums[middle] == nums[middle + 1] || middle % 2 == 1 && nums[middle] == nums[middle - 1])
                low = middle + 1;

            else
                high = middle - 1;
        }

        return -1;
    }
};