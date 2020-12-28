// https://leetcode.com/problems/sort-characters-by-frequency/

class Solution
{
public:
    string frequencySort(string s)
    {
        string result = "";
        unordered_map<char, int> freq;
        vector<pair<int, char>> heap;

        for (auto c : s)
            freq[c]++;

        for (auto pair : freq)
            heap.push_back({pair.second, pair.first});

        sort(heap.begin(), heap.end(), greater<pair<int, char>>());

        for (auto pair : heap)
            result += string(pair.first, pair.second);

        return result;
    }
};