// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return false;

        int start = 0;
        int end = nums.size() - 1;

        while (start <= end)
        {
            int middle = start + (end - start) / 2;

            if (nums[middle] == target)
                return true;

            if (nums[start] == nums[middle])
            {
                start++;
                continue;
            }

            bool pivotArray = nums[start] <= nums[middle];
            bool targetArray = nums[start] <= target;

            if (pivotArray ^ targetArray)
            {
                if (pivotArray)
                    start = middle + 1;
                else
                    end = middle - 1;
            }
            else
            {
                if (nums[middle] < target)
                {
                    start = middle + 1;
                }
                else
                {
                    end = middle - 1;
                }
            }
        }
        return false;
    }
};