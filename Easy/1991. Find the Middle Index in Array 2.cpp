// https://leetcode.com/problems/find-the-middle-index-in-array/

class Solution
{
public:
    int findMiddleIndex(vector<int> &nums)
    {
        vector<int> prefixSum(nums.size() + 3);

        for (int i = 0; i < nums.size(); ++i)
            prefixSum[i + 1] = prefixSum[i] + nums[i];

        for (int i = 1; i <= nums.size(); ++i)
            if (prefixSum[i - 1] == prefixSum[nums.size()] - prefixSum[i])
                return i - 1;

        return -1;
    }
};