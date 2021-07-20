// https://leetcode.com/problems/teemo-attacking/

class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int result = 0;

        for (int i = 0; i < timeSeries.size() - 1; ++i)
        {
            if (timeSeries[i] + duration > timeSeries[i + 1])
                result += (timeSeries[i + 1] - timeSeries[i]);

            else
                result += duration;
        }

        result += duration;

        return result;
    }
};