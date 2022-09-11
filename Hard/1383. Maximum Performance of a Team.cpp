// https://leetcode.com/problems/maximum-performance-of-a-team/

class Solution
{
public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
    {
        long result = 0;
        vector<pair<int, int>> input;
        priority_queue<int, vector<int>, greater<int>> speeds;

        long sum = 0;
        const int MOD = 1e9 + 7;

        for (int i = 0; i < n; ++i)
        {
            input.push_back({efficiency[i], speed[i]});
        }

        sort(input.begin(), input.end(), compare);

        for (int i = 0; i < n; ++i)
        {
            sum += input[i].second;

            if (i >= k)
            {
                int lowestSpeed = speeds.top();
                speeds.pop();

                sum -= lowestSpeed;
            }

            speeds.push(input[i].second);
            result = max(result, (sum * input[i].first));
        }

        return (int)(result % MOD);
    }

    static bool compare(pair<int, int> &firstPair, pair<int, int> &secondPair)
    {
        return firstPair.first > secondPair.first;
    }
};