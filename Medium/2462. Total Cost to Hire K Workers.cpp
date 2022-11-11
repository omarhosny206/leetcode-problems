// https://leetcode.com/problems/total-cost-to-hire-k-workers/

class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        long long result = 0;
        priority_queue<long long, vector<long long>, greater<long long>> leftValues;
        priority_queue<long long, vector<long long>, greater<long long>> rightValues;

        int i = 0;
        int j = costs.size() - 1;

        while (k--)
        {
            while (i <= j && leftValues.size() < candidates)
                leftValues.push(costs[i++]);

            while (j >= i && rightValues.size() < candidates)
                rightValues.push(costs[j--]);

            int left = (leftValues.empty()) ? INT_MAX : leftValues.top();

            int right = (rightValues.empty()) ? INT_MAX : rightValues.top();

            if (left <= right)
            {
                result += left;
                leftValues.pop();
            }

            else
            {
                result += right;
                rightValues.pop();
            }
        }

        return result;
    }
};