// https://leetcode.com/problems/daily-temperatures/

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        vector<int> result(T.size());
        stack<int> temps;

        for (int i = T.size() - 1; i >= 0; i--)
        {
            while (!temps.empty() && T[i] >= T[temps.top()])
                temps.pop();

            result[i] = (temps.empty()) ? 0 : temps.top() - i;
            temps.push(i);
        }

        return result;
    }
};