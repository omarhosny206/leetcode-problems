// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/

class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        for (int i = 0; i < prices.size() - 1; ++i)
        {
            int j = i + 1;

            while (j < prices.size() && prices[j] > prices[i])
                j++;

            prices[i] = (j == prices.size()) ? prices[i] : prices[i] - prices[j];
        }

        return prices;
    }
};