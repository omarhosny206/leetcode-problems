// https://leetcode.com/problems/k-diff-pairs-in-an-array/

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        int result = 0;
        unordered_map<int, int> freq;

        for (int &num : nums)
        {
            if (freq[num] == 1 && k == 0)
                result++;

            else if (freq[num] == 0)
            {
                if (freq[num - k] >= 1)
                    result++;

                if (freq[num + k] >= 1)
                    result++;
            }

            freq[num]++;
        }

        return result;
    }
};