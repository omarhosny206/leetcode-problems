// https://leetcode.com/problems/climbing-stairs/

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 0 || n == 1)
            return 1;

        vector<int> result(n + 1);

        result[0] = 1;
        result[1] = 1;

        for (int i = 2; i <= n; i++)
            result[i] = result[i - 1] + result[i - 2];

        return result[n];
    }
};