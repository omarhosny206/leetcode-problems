// https://leetcode.com/problems/fibonacci-number/

class Solution
{
public:
    int fib(int n)
    {
        vector<int> memo(n + 1, -1);

        return fib(n, memo);
    }

    int fib(int n, vector<int> &memo)
    {
        if (n <= 1)
            return n;

        if (memo[n] != -1)
            return memo[n];

        memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
        return memo[n];
    }
};