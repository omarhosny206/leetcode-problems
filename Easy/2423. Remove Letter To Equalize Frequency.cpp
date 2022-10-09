// https://leetcode.com/problems/remove-letter-to-equalize-frequency/

class Solution
{
public:
    bool equalFrequency(string word)
    {
        unordered_map<char, int> lettersFreq;
        map<int, int> frequenciesCounter;

        for (auto &c : word)
            lettersFreq[c]++;

        for (auto &pair : lettersFreq)
            frequenciesCounter[pair.second]++;

        if (frequenciesCounter.size() > 2)
            return false;

        auto first = frequenciesCounter.begin();
        auto second = first;

        second++;

        if (frequenciesCounter.size() == 1)
            return (lettersFreq.size() == 1 || first->first == 1);

        if (first->first == 1 && first->second == 1)
            return true;

        if (first->first == second->first - 1 && second->second == 1)
            return true;

        return false;
    }
};