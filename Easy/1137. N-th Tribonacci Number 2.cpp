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

        int result = 0;
        int first = 0;
        int second = 1;
        int third = 1;

        for (int i = 3; i <= n; ++i)
        {
            result = first + second + third;
            first = second;
            second = third;
            third = result;
        }

        return result;
    }
};