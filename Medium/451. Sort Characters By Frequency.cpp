// https://leetcode.com/problems/sort-characters-by-frequency/

class Solution
{
public:
    string frequencySort(string s)
    {
        string result = "";
        unordered_map<char, int> freq;
        priority_queue<pair<int, char>> maxHeap;

        for (char &c : s)
            freq[c]++;

        for (auto &pair : freq)
            maxHeap.push({pair.second, pair.first});

        while (!maxHeap.empty())
        {
            pair<int, char> value = maxHeap.top();
            maxHeap.pop();

            result += string(value.first, value.second);
        }

        return result;
    }
};