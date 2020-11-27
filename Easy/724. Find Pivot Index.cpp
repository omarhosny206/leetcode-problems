// https://leetcode.com/problems/find-pivot-index/

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int sum = 0;
        for (int num : nums)
            sum += num;

        int leftSum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (leftSum + nums[i] == sum)
                return i;

            leftSum += nums[i];
            sum -= nums[i];
        }

        return -1;
    }
};