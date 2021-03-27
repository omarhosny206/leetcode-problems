// https://leetcode.com/problems/find-the-highest-altitude/

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int maxAltitude = 0;
        int sum = 0;

        for (int num : gain)
        {
            sum += num;
            maxAltitude = max(maxAltitude, sum);
        }

        return maxAltitude;
    }
};