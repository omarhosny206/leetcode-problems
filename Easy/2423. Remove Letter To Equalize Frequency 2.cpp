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

        auto it1 = frequenciesCounter.begin();
        auto it2 = frequenciesCounter.begin();
        it2++;

        if (frequenciesCounter.size() == 1)
        {
            return (lettersFreq.size() == 1 || it1->first == 1);
        }

        if (it1->first == 1 && it1->second == 1)
            return true;

        if (it1->first == it2->first - 1 && it2->second == 1)
            return true;

        return false;
    }
};