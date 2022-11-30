// https://leetcode.com/problems/unique-number-of-occurrences/

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_set<int> occurrences;
        unordered_map<int, int> freq;

        for (int &num : arr)
            freq[num]++;

        for (auto &pair : freq)
        {
            if (occurrences.find(pair.second) != occurrences.end())
                return false;

            occurrences.insert(pair.second);
        }

        return true;
    }
};