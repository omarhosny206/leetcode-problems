// https://leetcode.com/problems/counting-bits/

class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> numBits(num + 1, 0);
        for (int i = 1; i <= num; ++i)
        {
            if (i % 2 == 0)
                numBits[i] = numBits[i / 2];
            else
                numBits[i] = numBits[i / 2] + 1;
        }
        return numBits;
    }
};
