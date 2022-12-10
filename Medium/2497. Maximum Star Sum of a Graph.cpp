// https://leetcode.com/problems/maximum-star-sum-of-a-graph/

class Solution
{
    int result = INT_MIN;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> values;
    unordered_map<int, int> sum;

public:
    int maxStarSum(vector<int> &vals, vector<vector<int>> &edges, int k)
    {
        for (int &val : vals)
            result = max(result, val);

        for (vector<int> &edge : edges)
        {
            if (sum[edge[0]] + vals[edge[1]] > sum[edge[0]])
            {
                sum[edge[0]] += vals[edge[1]];

                values[edge[0]].push(vals[edge[1]]);
                if (values[edge[0]].size() > k)
                {
                    int value = values[edge[0]].top();
                    sum[edge[0]] -= value;
                    values[edge[0]].pop();
                }
            }

            if (sum[edge[1]] + vals[edge[0]] > sum[edge[1]])
            {
                sum[edge[1]] += vals[edge[0]];

                values[edge[1]].push(vals[edge[0]]);
                if (values[edge[1]].size() > k)
                {
                    int value = values[edge[1]].top();
                    sum[edge[1]] -= value;
                    values[edge[1]].pop();
                }
            }
        }

        for (auto &pair : values)
            result = max(result, vals[pair.first] + sum[pair.first]);

        return result;
    }
};