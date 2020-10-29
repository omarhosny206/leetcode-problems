// https://leetcode.com/problems/climbing-stairs/

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 0 || n == 1)
            return 1;

        int first = 1;
        int second = 1;
        int num_ways = 2;
        for (int i = 2; i <= n; i++)
        {
            num_ways = first + second;
            first = second;
            second = num_ways;
        }

        return num_ways;
    }
};