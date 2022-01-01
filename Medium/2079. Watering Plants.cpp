// https://leetcode.com/problems/watering-plants/

class Solution
{
public:
    int wateringPlants(vector<int> &plants, int capacity)
    {
        int result = 0;
        int currentCapacity = capacity;

        for (int i = 0; i < plants.size(); ++i)
        {
            result += 1;

            if (currentCapacity < plants[i])
            {
                result += i;
                currentCapacity = capacity;
                result += i;
            }

            currentCapacity -= plants[i];
        }

        return result;
    }
};