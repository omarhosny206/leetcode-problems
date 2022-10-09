// https://leetcode.com/problems/the-employee-that-worked-on-the-longest-task/

class Solution
{
public:
    int hardestWorker(int n, vector<vector<int>> &logs)
    {
        int result = INT_MAX;

        unordered_map<int, int> value;
        int previous = 0;
        int maxValue = INT_MIN;

        for (vector<int> &log : logs)
        {
            value[log[0]] = max(value[log[0]], log[1] - previous);
            previous = log[1];
        }

        for (auto &pair : value)
        {
            if (pair.second == maxValue)
                result = min(result, pair.first);

            else if (pair.second > maxValue)
            {
                maxValue = pair.second;
                result = pair.first;
            }
        }

        return result;
    }
};