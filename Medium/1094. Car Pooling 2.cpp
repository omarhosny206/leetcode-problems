// https://leetcode.com/problems/car-pooling/

class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        vector<vector<int>> locations(trips.size() * 2, vector<int>(2));
        int currentCapacity = 0;

        for (vector<int> &trip : trips)
        {
            locations.push_back({trip[1], trip[0]});
            locations.push_back({trip[2], -1 * trip[0]});
        }

        sort(locations.begin(), locations.end());

        for (vector<int> &location : locations)
        {
            currentCapacity += location[1];

            if (currentCapacity > capacity)
                return false;
        }

        return true;
    }
};