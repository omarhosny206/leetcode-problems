// https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int result = 0;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] <= nums[i - 1])
            {
                int difference = nums[i - 1] - nums[i] + 1;
                result += difference;
                nums[i] += difference;
            }
        }

        return result;
    }
};