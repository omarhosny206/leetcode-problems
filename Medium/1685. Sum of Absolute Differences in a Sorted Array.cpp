// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/

class Solution
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    {
        int left_sum = 0;
        int right_sum = 0;
        int size = nums.size();

        for (int i = 0; i < size; i++)
            right_sum += nums[i];

        for (int i = 0; i < size; i++)
        {
            right_sum -= nums[i];
            left_sum += nums[i];

            int left = (i == 0) ? 0 : ((nums[i] * (i)) - (left_sum - nums[i]));
            int right = (i == size - 1) ? 0 : right_sum - (nums[i] * (size - i - 1));

            nums[i] = left + right;
        }

        return nums;
    }
};