// https://leetcode.com/problems/n-th-tribonacci-number/

class Solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;

        int x = 0, xx = 1, xxx = 1;
        int result = 0;
        for (int i = 3; i <= n; ++i)
        {
            result = x + xx + xxx;
            x = xx;
            xx = xxx;
            xxx = result;
        }
        return result;
    }
};