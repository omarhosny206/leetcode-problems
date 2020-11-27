// https://leetcode.com/problems/min-cost-climbing-stairs/

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int a = 0;
        int b = 0;

        for (int i = 0; i < cost.size(); ++i)
        {
            int c = cost[i] + min(a, b);
            b = a;
            a = c;
        }

        return min(a, b);
    }
};