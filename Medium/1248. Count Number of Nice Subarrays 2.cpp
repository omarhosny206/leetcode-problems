// https://leetcode.com/problems/count-number-of-nice-subarrays/

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int result = 0;
        unordered_map<int, int> freq;
        int i = 0;
        int sum = 0;

        freq[0] = 1;

        while (i < nums.size())
        {
            sum += isOdd(nums[i]) ? 1 : 0;
            freq[sum]++;
            result += freq[sum - k];
            i++;
        }

        return result;
    }

    bool isOdd(int num)
    {
        return num % 2 == 1;
    }
};