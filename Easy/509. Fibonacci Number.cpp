// https://leetcode.com/problems/fibonacci-number/

class Solution
{
public:
    int fib(int n)
    {
        int result;

        if (n <= 1)
            return n;

        int first = 0;
        int second = 1;

        for (int i = 2; i <= n; ++i)
        {
            result = first + second;
            first = second;
            second = result;
        }

        return result;
    }
};