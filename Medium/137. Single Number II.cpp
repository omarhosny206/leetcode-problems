// https://leetcode.com/problems/single-number-ii/

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        map<int, int> freq;
        for (int n : nums)
            freq[n]++;
        for (int n : nums)
            if (freq[n] == 1)
                return n;
        return -1;
    }
};