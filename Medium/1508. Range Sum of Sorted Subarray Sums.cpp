// https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/

class Solution
{
public:
    int rangeSum(vector<int> &nums, int n, int left, int right)
    {
        int result = 0;
        vector<int> prefixSum;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                prefixSum.push_back(sum);
            }
        }
        sort(prefixSum.begin(), prefixSum.end());

        result += accumulate(prefixSum.begin() + left - 1, prefixSum.begin() + right, 0LL) % 1000000007;

        return result;
    }
};