// https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/

class Solution
{
public:
    vector<int> getNoZeroIntegers(int n)
    {
        for (int i = 1; i < n; ++i)
            if (hasNoZero(i) && hasNoZero(n - i))
                return {i, n - i};

        return {};
    }

    bool hasNoZero(int num)
    {
        while (num != 0)
        {
            if (num % 10 == 0)
                return false;

            num /= 10;
        }

        return true;
    }
};