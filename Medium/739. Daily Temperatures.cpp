// https://leetcode.com/problems/daily-temperatures/

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> result(temperatures.size());
        stack<int> values;

        for (int i = temperatures.size() - 1; i >= 0; i--)
        {
            while (!values.empty() && temperatures[i] >= temperatures[values.top()])
                values.pop();

            result[i] = ((values.empty()) ? 0 : values.top() - i);
            values.push(i);
        }

        return result;
    }
};