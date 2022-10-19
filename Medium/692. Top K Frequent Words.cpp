// https://leetcode.com/problems/top-k-frequent-words/

class Solution
{
    struct Comparator
    {
        bool operator()(pair<int, string> &a, pair<int, string> &b)
        {
            return (a.first < b.first) || ((a.first == b.first) && (a.second > b.second));
        }
    };

public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        vector<string> result;
        unordered_map<string, int> freq;
        priority_queue<pair<int, string>, vector<pair<int, string>>, Comparator> vals;

        for (string &word : words)
            freq[word]++;

        for (auto &pair : freq)
            vals.push({pair.second, pair.first});

        while (k--)
        {
            string value = vals.top().second;
            vals.pop();

            result.push_back(value);
        }

        return result;
    }
};