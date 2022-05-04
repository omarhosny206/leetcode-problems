// https://leetcode.com/problems/max-number-of-k-sum-pairs/

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        int result = 0;
        unordered_map<int, int> freq;

        for (int &num : nums)
            freq[num]++;

        for (int &num : nums)
        {
            if ((num != k - num && freq[num] > 0 && freq[k - num] > 0) || (num == k - num && freq[k - num] > 1))
            {
                freq[num]--;
                freq[k - num]--;
                result++;
            }
        }

        return result;
    }
};