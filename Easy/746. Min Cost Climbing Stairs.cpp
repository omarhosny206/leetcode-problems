// https://leetcode.com/problems/min-cost-climbing-stairs/

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int size = cost.size();

        vector<int> DP(size + 1, 0);

        if (size == 1)
            return cost[0];

        for (int i = 2; i < size + 1; i++)
            DP[i] = min(DP[i - 1] + cost[i - 1], DP[i - 2] + cost[i - 2]);

        return DP[size];
    }
};