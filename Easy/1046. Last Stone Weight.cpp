// https://leetcode.com/problems/last-stone-weight/

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int, vector<int>> maxHeap;

        for (int &stone : stones)
            maxHeap.push(stone);

        while (maxHeap.size() > 1)
        {
            int first = maxHeap.top();
            maxHeap.pop();

            int second = maxHeap.top();
            maxHeap.pop();

            int difference = first - second;

            if (difference > 0)
                maxHeap.push(difference);
        }

        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};