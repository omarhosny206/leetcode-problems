// https://leetcode.com/problems/sort-characters-by-frequency/

class Solution
{
public:
    string frequencySort(string s)
    {
        string result = "";
        unordered_map<char, int> freq;
        vector<pair<int, char>> values;

        for (auto &c : s)
            freq[c]++;

        for (auto &pair : freq)
            values.push_back({pair.second, pair.first});

        sort(values.begin(), values.end(), greater<pair<int, char>>());

        for (auto &pair : values)
            result += string(pair.first, pair.second);

        return result;
    }
};