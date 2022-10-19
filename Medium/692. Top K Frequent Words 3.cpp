// https://leetcode.com/problems/top-k-frequent-words/

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        vector<string> result;
        unordered_map<string, int> freq;
        vector<pair<int, string>> vals;

        for (string &word : words)
            freq[word]++;

        for (auto &pair : freq)
            vals.push_back({pair.second, pair.first});

        sort(vals.begin(), vals.end(), compare);
        int i = 0;

        while (k--)
        {
            string value = vals[i++].second;
            result.push_back(value);
        }

        return result;
    }

    static bool compare(pair<int, string> &a, pair<int, string> &b)
    {
        return (a.first > b.first) || ((a.first == b.first) && (a.second < b.second));
    };
};