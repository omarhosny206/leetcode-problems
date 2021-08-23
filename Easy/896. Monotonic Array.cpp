// https://leetcode.com/problems/monotonic-array/

class Solution
{
public:
    bool isMonotonic(vector<int> &nums)
    {
        bool isIncreasing = false;
        bool isDecreasing = false;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[i - 1])
                isIncreasing = true;

            else if (nums[i] < nums[i - 1])
                isDecreasing = true;

            if (isIncreasing && isDecreasing)
                return false;
        }

        return true;
    }
};