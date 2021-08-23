// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int result = 0;
        int i = 0;
        int j = 0;
        int zeros = 0;

        while (j < nums.size())
        {
            if (nums[j] == 0)
                zeros++;

            while (zeros > 1)
            {
                if (nums[i] == 0)
                    zeros--;

                i++;
            }

            result = max(result, j - i);
            j++;
        }

        return result;
    }
};