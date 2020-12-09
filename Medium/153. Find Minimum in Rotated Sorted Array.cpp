// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            int middle = left + (right - left) / 2;

            if (nums[middle] < nums[right])
                right = middle;

            else
                left = middle + 1;
        }

        return nums[right];
    }
};