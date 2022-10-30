// https://leetcode.com/problems/destroy-sequential-targets/

class Solution
{
public:
    int destroyTargets(vector<int> &nums, int space)
    {
        int result = 1e9 + 1;
        unordered_map<int, int> freq;
        int maxValue = INT_MIN;

        sort(nums.begin(), nums.end());

        for (int &num : nums)
        {
            int value = num % space;
            freq[value]++;
        }

        for (int &num : nums)
        {
            int value = freq[num % space];

            if (maxValue < value)
            {
                result = num;
                maxValue = value;
            }
        }

        return result;
    }
};