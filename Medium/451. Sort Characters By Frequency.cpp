// https://leetcode.com/problems/sort-characters-by-frequency/

class Solution
{
public:
    string frequencySort(string s)
    {
        string result = "";
        unordered_map<char, int> freq;
        priority_queue<pair<int, char>> max_heap;

        for (char c : s)
            freq[c]++;

        for (auto pair : freq)
            max_heap.push({pair.second, pair.first});

        while (!max_heap.empty())
        {
            int k = max_heap.top().first;

            while (k--)
                result += max_heap.top().second;

            max_heap.pop();
        }

        return result;
    }
};