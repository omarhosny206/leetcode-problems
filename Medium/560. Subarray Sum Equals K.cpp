// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int result = 0;
        int sum = 0;
        unordered_map<int, int> freq;

        freq[0] = 1;

        for (int &num : nums)
        {
            sum += num;
            result += freq[sum - k];
            freq[sum]++;
        }

        return result;
    }
};