// https://leetcode.com/problems/online-stock-span/

class StockSpanner
{
    stack<pair<int, int>> stock;

public:
    StockSpanner()
    {
    }

    int next(int price)
    {
        int days = 1;

        while (!stock.empty() && stock.top().first <= price)
        {
            days += stock.top().second;
            stock.pop();
        }

        stock.push({price, days});
        return days;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */