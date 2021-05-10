// https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/

class Solution
{
public:
    vector<int> minSubsequence(vector<int> &nums)
    {
        vector<int> result;
        int sum = 0;
        int currentSum = 0;
        int i = nums.size() - 1;

        sort(nums.begin(), nums.end());

        for (int &num : nums)
            sum += num;

        while (currentSum <= sum)
        {
            result.push_back(nums[i]);
            currentSum += nums[i];
            sum -= nums[i];
            i--;
        }

        return result;
    }
};