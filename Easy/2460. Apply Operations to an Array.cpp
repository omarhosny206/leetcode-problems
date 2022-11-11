// https://leetcode.com/problems/apply-operations-to-an-array/

class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {
        int i = 0;
        int j = 0;

        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] == nums[i + 1])
            {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        while (j < nums.size())
        {
            if (nums[j] != 0)
                nums[i++] = nums[j];

            j++;
        }

        while (i < nums.size())
            nums[i++] = 0;

        return nums;
    }
};