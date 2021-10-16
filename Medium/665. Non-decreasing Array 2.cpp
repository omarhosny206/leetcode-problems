// https://leetcode.com/problems/non-decreasing-array/

class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        bool oneChangeMade = false;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i - 1] > nums[i])
            {
                if (oneChangeMade)
                    return false;

                oneChangeMade = true;

                if (i == nums.size() - 1 || i == 1)
                    continue;

                else if (!(nums[i] >= nums[i - 2] || nums[i + 1] >= nums[i - 1]))
                    return false;
            }
        }
        return true;
    }
};