// https://leetcode.com/problems/find-the-middle-index-in-array/

class Solution
{
public:
    int findMiddleIndex(vector<int> &nums)
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