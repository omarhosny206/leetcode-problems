// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0;
        vector<int> maxSell(prices.size());

        for (int i = prices.size() - 1; i >= 0; --i)
        {
            if (maxProfit < prices[i])
                maxProfit = prices[i];

            maxSell[i] = maxProfit;
        }

        maxProfit = 0;

        for (int i = 0; i < prices.size(); ++i)
            if (maxSell[i] - prices[i] > maxProfit)
                maxProfit = maxSell[i] - prices[i];

        return maxProfit;
    }
};