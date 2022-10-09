// https://leetcode.com/problems/the-employee-that-worked-on-the-longest-task/

class Solution
{
public:
    int hardestWorker(int n, vector<vector<int>> &logs)
    {
        int result = INT_MAX;

        int previous = 0;
        int maxValue = INT_MIN;

        for (vector<int> &log : logs)
        {
            if (log[1] - previous > maxValue)
            {
                maxValue = log[1] - previous;
                result = log[0];
            }

            else if (log[1] - previous == maxValue)
                result = min(result, log[0]);

            previous = log[1];
        }

        return result;
    }
};