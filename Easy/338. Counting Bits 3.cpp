// https://leetcode.com/problems/counting-bits/

class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> result(num + 1, 0);

        for (int i = 1; i <= num; ++i)
            result[i] = getNumBits(i);

        return result;
    }

    int getNumBits(int num)
    {
        int result = 0;

        while (num > 0)
        {
            if (num % 2 == 1)
                result++;

            num = num / 2;
        }

        return result;
    }
};