// https://leetcode.com/problems/integer-break/

class Solution
{
public:
    int integerBreak(int n)
    {
        vector<int> DP(n + 1);
        DP[1] = 1;
        DP[2] = 1;

        for (int i = 3; i <= n; i++)
            for (int j = 1; j < i; j++)
                DP[i] = max(max(DP[i], j * DP[i - j]), j * (i - j));

        return DP[n];
    }
};