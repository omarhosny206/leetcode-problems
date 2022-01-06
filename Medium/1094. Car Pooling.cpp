// https://leetcode.com/problems/car-pooling/

class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> locations;
        int currentCapacity = 0;

        for (vector<int> &trip : trips)
        {
            locations.push({trip[1], trip[0]});
            locations.push({trip[2], -1 * trip[0]});
        }

        while (locations.size() > 0)
        {
            pair<int, int> location = locations.top();
            locations.pop();

            currentCapacity += location.second;

            if (currentCapacity > capacity)
                return false;
        }

        return true;
    }
};