// https://leetcode.com/problems/number-of-common-factors/submissions/

class Solution
{
public:
    int commonFactors(int a, int b)
    {
        int result = 0;
        int size = min(a, b);

        for (int i = 1; i <= size; ++i)
            if (a % i == 0 && b % i == 0)
                result++;

        return result;
    }
};