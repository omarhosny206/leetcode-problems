// https://leetcode.com/problems/move-zeroes/

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {

        int lastNonZeroFoundAt = 0;

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != 0)
                swap(nums[lastNonZeroFoundAt++], nums[i]);
    }
};