// https://leetcode.com/problems/longest-harmonious-subsequence/

class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        int result = 0;
        unordered_map<int, int> freq;

        for (int num : nums)
        {
            freq[num]++;

            if (freq.find(num - 1) != freq.end())
                result = max(result, freq[num] + freq[num - 1]);

            if (freq.find(num + 1) != freq.end())
                result = max(result, freq[num] + freq[num + 1]);
        }

        return result;
    }
};