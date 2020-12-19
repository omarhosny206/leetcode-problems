// https://leetcode.com/problems/top-k-frequent-elements/

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> result;
        unordered_map<int, int> freq;

        for (int num : nums)
            freq[num]++;

        priority_queue<pair<int, int>> max_heap;

        for (auto pair : freq)
            max_heap.push({pair.second, pair.first});

        while (k--)
        {
            result.push_back(max_heap.top().second);
            max_heap.pop();
        }

        return result;
    }
};