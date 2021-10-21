// https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/

class Solution
{
public:
    int countKDifference(vector<int> &nums, int k)
    {
        int result = 0;
        unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (freq[nums[i] - k])
                result += freq[nums[i] - k];

            if (freq[nums[i] + k])
                result += freq[nums[i] + k];

            freq[nums[i]]++;
        }

        return result;
    }
};