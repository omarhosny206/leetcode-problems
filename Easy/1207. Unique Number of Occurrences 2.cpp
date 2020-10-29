// https://leetcode.com/problems/unique-number-of-occurrences/

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_set<int> occurrences;
        map<int, int> numFreq;

        for (int n : arr)
            numFreq[n]++;

        for (pair<int, int> p : numFreq)
            occurrences.insert(p.second);

        return occurrences.size() == numFreq.size();
    }
};