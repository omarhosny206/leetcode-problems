// https://leetcode.com/problems/largest-number-at-least-twice-of-others/

class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        int index = getMaximumIndex(nums);

        for (int i = 0; i < nums.size(); ++i)
            if (i != index && nums[index] < nums[i] * 2)
                return -1;

        return index;
    }

    int getMaximumIndex(vector<int> &nums)
    {
        int index = 0;
        int maxVal = nums[index];

        for (int i = 0; i < nums.size(); ++i)
        {
            if (maxVal < nums[i])
            {
                index = i;
                maxVal = nums[index];
            }
        }

        return index;
    }
};