
class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        int result = 0;
        priority_queue<pair<int, int>> maxHeap;

        for (int i = 0; i < costs.size(); ++i)
            maxHeap.push({costs[i][1] - costs[i][0], i});

        int size = maxHeap.size();
        while (maxHeap.size() != size / 2)
        {
            int index = maxHeap.top().second;
            maxHeap.pop();
            result += costs[index][0];
        }

        while (!maxHeap.empty())
        {
            int index = maxHeap.top().second;
            maxHeap.pop();
            result += costs[index][1];
        }

        return result;
    }
};