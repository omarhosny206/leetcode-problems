// https://leetcode.com/problems/subarrays-with-k-different-integers/

class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return countWindows(nums, k) - countWindows(nums, k - 1);
    }

    int countWindows(vector<int> &nums, int k)
    {
        int result = 0;
        unordered_map<int, int> freq;
        int i = 0;
        int j = 0;
        int counter = 0;

        while (j < nums.size())
        {
            if (++freq[nums[j]] == 1)
                counter++;

            while (counter > k)
            {
                if (--freq[nums[i]] == 0)
                    counter--;

                i++;
            }

            result += j - i;
            j++;
        }

        return result;
    }
};