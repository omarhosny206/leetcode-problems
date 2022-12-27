// https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/

class Solution
{
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
    {
        int result = 0;
        vector<int> differnces;

        for (int i = 0; i < capacity.size(); ++i)
            differnces.push_back(capacity[i] - rocks[i]);

        sort(differnces.begin(), differnces.end(), compare);

        for (int &difference : differnces)
        {
            if (additionalRocks >= difference)
            {
                additionalRocks -= difference;
                result++;
            }

            if (additionalRocks == 0)
                return result;
        }

        return result;
    }

    static bool compare(int &first, int &second)
    {
        return first < second;
    }
};