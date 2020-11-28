// https://leetcode.com/problems/sort-array-by-increasing-frequency/

class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        vector<int> result;

        map<int, int> freq;
        for (int num : nums)
            freq[num]++;

        vector<pair<int, int>> numbers;
        for (auto pair : freq)
            numbers.push_back(pair);

        sort(numbers.begin(), numbers.end(), comp);

        for (auto pair : numbers)
            while ((pair.second)--)
                result.push_back(pair.first);

        return result;
    }

    static bool comp(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.second == b.second)
            return a > b;
        return a.second < b.second;
    }
};