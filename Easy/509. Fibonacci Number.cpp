// https://leetcode.com/problems/fibonacci-number/

class Solution
{
public:
    int fib(int N)
    {
        if (N <= 1)
            return N;

        int result = 0;
        int first = 0;
        int second = 1;

        for (int i = 2; i <= N; ++i)
        {
            result = first + second;
            first = second;
            second = result;
        }

        return result;
    }
};