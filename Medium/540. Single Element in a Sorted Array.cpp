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
        int i = 0;
        int j = nums.size() - 1;

        while (i <= j)
        {
            int middle = i + (j - i) / 2;

            if (nums[middle] != nums[middle - 1] && nums[middle] != nums[middle + 1])
                return nums[middle];

            else if (middle % 2 == 0 && nums[middle] == nums[middle + 1] || middle % 2 == 1 && nums[middle] == nums[middle - 1])
                i = middle + 1;

            else
                j = middle - 1;
        }

        return -1;
    }
};