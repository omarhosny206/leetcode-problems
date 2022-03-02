// https://leetcode.com/problems/counting-bits/

class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> result(num + 1, 0);

        for (int i = 1; i <= num; ++i)
        {
            if (i % 2 == 0)
                result[i] = result[i / 2];

            else
                result[i] = result[i / 2] + 1;
        }

        return result;
    }
};
