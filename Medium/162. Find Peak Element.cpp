// https://leetcode.com/problems/find-peak-element/

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int middle = left + (right - left) / 2;
            if (nums[middle] < nums[middle + 1])
                left = middle + 1;
            else
                right = middle;
        }
        return left;
    }
};