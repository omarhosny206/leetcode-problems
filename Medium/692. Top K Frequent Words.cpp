// https://leetcode.com/problems/top-k-frequent-words/

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        vector<string> result;
        map<string, int> freq;
        for (string word : words)
            freq[word]++;

        auto comp = [](pair<int, string> &a, pair<int, string> &b) {
            if (a.first != b.first)
            {
                return a.first < b.first;
            }
            return a.second > b.second;
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> maxHeap(comp);

        for (auto pair : freq)
            maxHeap.push({pair.second, pair.first});

        while (k--)
        {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};