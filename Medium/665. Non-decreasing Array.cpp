// https://leetcode.com/problems/non-decreasing-array/

class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        int counter = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] < nums[i - 1])
            {
                if (i == 1 || nums[i] >= nums[i - 2])
                {
                    nums[i - 1] = nums[i];
                    counter++;
                }
                else
                {
                    nums[i] = nums[i - 1];
                    counter++;
                }
            }
        }

        return counter <= 1;
    }
};