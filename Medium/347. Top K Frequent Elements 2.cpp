
class Solution
{
    struct Comparator
    {
        bool operator()(pair<int, int> &firstPair, pair<int, int> &secondPair)
        {
            return firstPair.first > secondPair.first;
        }
    };

public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> result;
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> maxHeap;

        for (int &num : nums)
            freq[num]++;

        for (auto &pair : freq)
        {
            maxHeap.push({pair.second, pair.first});

            if (maxHeap.size() > k)
                maxHeap.pop();
        }

        while (k--)
        {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};