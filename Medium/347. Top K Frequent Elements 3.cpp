
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> result(k);
        unordered_map<int, int> freq;
        vector<pair<int, int>> values;

        for (int &num : nums)
            freq[num]++;

        for (auto &pair : freq)
            values.push_back(pair);

        sort(values.begin(), values.end(), compare);

        for (int i = 0; i < k; ++i)
            result[i] = values[i].first;

        return result;
    }

    static bool compare(pair<int, int> &firstPair, pair<int, int> &secondPair)
    {
        return firstPair.second > secondPair.second;
    }
};