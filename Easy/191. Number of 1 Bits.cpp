// https://leetcode.com/problems/number-of-1-bits/

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        if (n == 0)
            return 0;

        return (n % 2) + hammingWeight(n / 2);
    }
};