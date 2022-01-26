// https://leetcode.com/problems/stone-game-iv/

class Solution
{
public:
    bool winnerSquareGame(int n)
    {
        vector<int> dp(n + 1, -1);
        return dfs(n, dp) == 1;
    }

    int dfs(int n, vector<int> &dp)
    {
        if (n == 0)
            return false;

        if (dp[n] != -1)
            return dp[n];

        for (int i = 1; i * i <= n; i++)
        {
            if (dfs(n - i * i, dp) == 0)
            {
                dp[n] = 1;
                break;
            }
        }

        if (dp[n] == -1)
            dp[n] = 0;

        return dp[n];
    }
};