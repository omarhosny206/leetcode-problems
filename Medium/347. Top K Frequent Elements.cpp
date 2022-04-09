// https://leetcode.com/problems/top-k-frequent-elements/

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> result;
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>> maxHeap;

        for (int &num : nums)
            freq[num]++;

        for (auto &pair : freq)
            maxHeap.push({pair.second, pair.first});

        while (k--)
        {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};