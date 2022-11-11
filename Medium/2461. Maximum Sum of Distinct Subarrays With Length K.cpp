// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        long long result = 0;
        long long sum = 0;
        unordered_map<int, int> freq;

        int i = 0;
        int j = 0;
        int counter = 0;

        while (j < nums.size())
        {
            if (++freq[nums[j]] > 1)
                counter++;

            sum += nums[j];

            while (counter > 0)
            {
                if (--freq[nums[i]] >= 1)
                    counter--;

                sum -= nums[i];
                i++;
            }

            int windowSize = j - i + 1;

            if (windowSize == k && counter == 0)
            {
                result = max(result, sum);
                sum -= nums[i];
                freq[nums[i]]--;
                i++;
            }

            j++;
        }

        return result;
    }
};