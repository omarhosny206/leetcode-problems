// https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/

class Solution
{
public:
    int minCost(string s, vector<int> &cost)
    {
        int min_cost = 0;
        int i = 0;
        while (i < s.length() - 1)
        {
            if (s[i] == s[i + 1])
            {
                min_cost += min(cost[i + 1], cost[i]);

                if (cost[i + 1] < cost[i])
                    cost[i + 1] = cost[i];
            }

            i++;
        }

        return min_cost;
    }
};