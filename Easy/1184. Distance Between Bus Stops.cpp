// https://leetcode.com/problems/distance-between-bus-stops/

class Solution
{
public:
    int distanceBetweenBusStops(vector<int> &distance, int start, int destination)
    {
        int first = getDistance(distance, start, destination);
        int second = getDistance(distance, destination, start);
        return min(first, second);
    }

    int getDistance(vector<int> &distance, int start, int destination)
    {
        int result = 0;
        int i = start;

        while (i != destination)
        {
            result += distance[i];
            i = (i + 1) % distance.size();
        }

        return result;
    }
};