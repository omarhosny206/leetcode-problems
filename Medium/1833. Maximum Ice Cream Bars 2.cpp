// https://leetcode.com/problems/maximum-ice-cream-bars/

class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        int result = 0;
        int i = 0;
        
        sort(costs.begin(), costs.end());

        while (i < costs.size() && coins >= costs[i])
        {
            result++;
            coins -= costs[i];
            i++;
        }

        return result;
    }
};