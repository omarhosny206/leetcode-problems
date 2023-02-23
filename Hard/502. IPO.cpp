
class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int result;
        priority_queue<pair<int, int>> maxProfits;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minCapitals;

        for (int i = 0; i < profits.size(); ++i)
            minCapitals.push({capital[i], profits[i]});

        while (k--)
        {
            while (!minCapitals.empty() && minCapitals.top().first <= w)
            {
                pair<int, int> value = minCapitals.top();
                minCapitals.pop();

                maxProfits.push({value.second, value.first});
            }

            if (!maxProfits.empty())
            {
                pair<int, int> value = maxProfits.top();
                maxProfits.pop();

                w += value.first;
            }
        }

        result = w;
        return result;
    }
};