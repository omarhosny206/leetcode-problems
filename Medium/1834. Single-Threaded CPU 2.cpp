// https://leetcode.com/problems/single-threaded-cpu/

class Solution
{
    struct Comparator
    {
        bool operator()(pair<int, int> &a, pair<int, int> &b)
        {
            if (a.first == b.first)
                return a.second > b.second;

            return a.first > b.first;
        }
    };

public:
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        vector<int> result;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> values;

        for (int i = 0; i < tasks.size(); ++i)
            tasks[i].push_back(i);

        sort(tasks.begin(), tasks.end(), compare);

        long long currentTime = tasks[0][0];
        int i = 0;

        while (!values.empty() || i < tasks.size())
        {
            while (i < tasks.size() && currentTime >= tasks[i][0])
            {
                values.push({tasks[i][1], tasks[i][2]});
                ++i;
            }

            if (values.empty())
            {
                currentTime = tasks[i][0];
                continue;
            }

            pair<int, int> value = values.top();
            values.pop();

            currentTime += value.first;
            result.push_back(value.second);
        }

        return result;
    }

    static bool compare(vector<int> &first, vector<int> &second)
    {
        return first[0] < second[0];
    }
};