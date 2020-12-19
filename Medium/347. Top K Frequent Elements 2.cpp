// https://leetcode.com/problems/top-k-frequent-elements/

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> result(k);
        unordered_map<int, int> freq;

        for (int num : nums)
            freq[num]++;

        vector<pair<int, int>> max_heap;

        for (auto pair : freq)
            max_heap.push_back(pair);

        sort(max_heap.begin(), max_heap.end(), comp);

        for (int i = 0; i < k; ++i)
            result[i] = max_heap[i].first;

        return result;
    }

    static bool comp(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
    }
};