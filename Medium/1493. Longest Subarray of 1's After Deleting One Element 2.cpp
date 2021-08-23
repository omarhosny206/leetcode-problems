// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int result = 0;
        int i = 0;
        int j = 0;
        int ones = 0;
        int zeros = 0;

        while (j < nums.size())
        {
            (nums[j] == 1) ? ones++ : zeros++;

            while (zeros > 1)
            {
                (nums[i] == 1) ? ones-- : zeros--;
                i++;
            }

            result = max(result, ones - !zeros);
            j++;
        }

        return result;
    }
};