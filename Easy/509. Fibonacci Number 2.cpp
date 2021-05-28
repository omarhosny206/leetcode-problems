// https://leetcode.com/problems/fibonacci-number/

class Solution
{
public:
    int fib(int N)
    {
        vector<int> memo(N + 1, INT_MAX);

        return Fibonacci(N, memo);
    }

    int Fibonacci(int N, vector<int> &memo)
    {
        if (N <= 1)
            return N;

        if (memo[N] != INT_MAX)
            return memo[N];

        memo[N] = Fibonacci(N - 1, memo) + Fibonacci(N - 2, memo);
        return memo[N];
    }
};