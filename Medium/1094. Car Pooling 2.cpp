// https://leetcode.com/problems/car-pooling/

class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        vector<pair<int, int>> locations;
        int currentCapacity = 0;

        for (vector<int> &trip : trips)
        {
            locations.push_back({trip[1], trip[0]});
            locations.push_back({trip[2], -1 * trip[0]});
        }

        sort(locations.begin(), locations.end());

        for (pair<int,int> &location : locations)
        {
            currentCapacity += location.second;

            if (currentCapacity > capacity)
                return false;
        }

        return true;
    }
};