// https://leetcode.com/problems/coin-change-2/

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {

        vector<int> DP(amount + 1, 0);
        DP[0] = 1;

        for (int coin : coins)
            for (int i = coin; i <= amount; ++i)
                DP[i] += DP[i - coin];

        return DP[amount];
    }
};