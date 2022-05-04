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
            if (freq[num] > 0 && freq[k - num] > 0)
            {
                freq[num]--;
                freq[k - num]--;
                result++;

                if (freq[num] < 0)
                    result--;
            }
        }

        return result;
    }
};