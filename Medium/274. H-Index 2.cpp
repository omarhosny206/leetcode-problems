// https://leetcode.com/problems/h-index/

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int h;
        priority_queue<int> maxHeap(begin(citations), end(citations));

        for (h = 0; !maxHeap.empty() && h < maxHeap.top(); ++h)
            maxHeap.pop();

        return h;
    }
};