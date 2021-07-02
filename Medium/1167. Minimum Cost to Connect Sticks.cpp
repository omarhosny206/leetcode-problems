// https://leetcode.com/problems/minimum-cost-to-connect-sticks/

class Solution
{
public:
    int MinimumCost(vector<int> &sticks)
    {
        int result = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int &stick : sticks)
            minHeap.push(stick);

        while (minHeap.size() > 1)
        {
            int first = minHeap.top();
            minHeap.pop();

            int second = minHeap.top();
            minHeap.pop();

            int cost = first + second;
            result += cost;

            minHeap.push(cost);
        }

        return result;
    }
};