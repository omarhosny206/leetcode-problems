// https://leetcode.com/problems/single-number/

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int result = 0;
        for (int n : nums)
            result ^= n;
        return result;
    }
};