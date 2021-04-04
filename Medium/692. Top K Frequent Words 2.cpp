// https://leetcode.com/problems/top-k-frequent-words/

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        vector<string> result;
        map<string, int> freq;
        vector<pair<int, string>> maxHeap;

        for (string word : words)
            freq[word]++;

        for (auto pair : freq)
            maxHeap.push_back({pair.second, pair.first});

        sort(maxHeap.begin(), maxHeap.end(), comp);
        int i = 0;
        while (i < k)
        {
            result.push_back(maxHeap[i].second);
            i++;
        }

        return result;
    }

    static bool comp(pair<int, string> &a, pair<int, string> &b)
    {
        if (a.first != b.first)
        {
            return a.first > b.first;
        }
        return a.second < b.second;
    };
};