// https://leetcode.com/problems/word-subsets/

class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        vector<string> result;
        vector<int> targetFreq(26);

        for (string &word : words2)
        {
            vector<int> currentFreq = countFrequency(word);

            for (int i = 0; i < currentFreq.size(); ++i)
                targetFreq[i] = max(targetFreq[i], currentFreq[i]);
        }

        for (string &word : words1)
        {
            vector<int> currentFreq = countFrequency(word);
            int i = 0;
            for (i; i < currentFreq.size(); ++i)
                if (targetFreq[i] > currentFreq[i])
                    break;

            if (i == 26)
                result.push_back(word);
        }

        return result;
    }

    vector<int> countFrequency(string &word)
    {
        vector<int> freq(26);

        for (char &c : word)
            freq[c - 'a']++;

        return freq;
    }
};