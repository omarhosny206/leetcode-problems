// https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/

class Solution
{
public:
    int minCost(string colors, vector<int> &cost)
    {
        int result = 0;
        int i = 0;

        while (i < colors.length() - 1)
        {
            if (colors[i] == colors[i + 1])
            {
                result += min(cost[i + 1], cost[i]);

                if (cost[i + 1] < cost[i])
                    cost[i + 1] = cost[i];
            }

            i++;
        }

        return result;
    }
};