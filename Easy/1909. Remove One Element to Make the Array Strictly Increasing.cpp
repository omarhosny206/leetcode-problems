// https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/

class Solution
{
public:
    bool canBeIncreasing(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
            if (isStrictlyGreater(nums, i))
                return true;

        return false;
    }

    bool isStrictlyGreater(vector<int> &nums, int removedPosition)
    {
        int value = INT_MIN;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (i != removedPosition)
            {
                if (value >= nums[i])
                    return false;

                value = nums[i];
            }
        }

        return true;
    }
};