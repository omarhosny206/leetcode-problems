// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<long long> maxBuy(prices.size());
        vector<long long> maxSell(prices.size());
        long long buy;
        long long sell;

        for (int i = 0; i < prices.size(); ++i)
        {
            buy = -prices[i] + (i >= 2 ? maxSell[i - 2] : 0);
            maxBuy[i] = (i == 0 ? buy : max(maxBuy[i - 1], buy));

            sell = (i == 0) ? 0 : maxBuy[i - 1] + prices[i];
            maxSell[i] = (i == 0 ? sell : max(maxSell[i - 1], sell));
        }

        return maxSell[prices.size() - 1];
    }
};