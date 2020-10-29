// https://leetcode.com/problems/maximum-subarray/

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {

        int MAX = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            nums[i] = max(nums[i - 1] + nums[i], nums[i]);
            MAX = max(MAX, nums[i]);
        }

        return MAX;
    }
};
