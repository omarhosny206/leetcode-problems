// https://leetcode.com/problems/single-number/

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> freq;

        for (int &num : nums)
            freq[num]++;

        for (int &num : nums)
            if (freq[num] == 1)
                return num;

        return 0;
    }
};