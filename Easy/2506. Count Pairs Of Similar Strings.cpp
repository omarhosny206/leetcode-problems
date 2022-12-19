// https://leetcode.com/problems/count-pairs-of-similar-strings/

class Solution
{
public:
    int similarPairs(vector<string> &words)
    {
        int result = 0;

        for (int i = 0; i < words.size(); ++i)
        {
            vector<bool> firstFreq = getFreq(words[i]);

            for (int j = i + 1; j < words.size(); ++j)
            {
                vector<bool> secondFreq = getFreq(words[j]);

                if (firstFreq == secondFreq)
                    result++;
            }
        }

        return result;
    }

    vector<bool> getFreq(string &word)
    {
        vector<bool> freq(26);

        for (char &c : word)
            freq[c - 'a'] = true;

        return freq;
    }
};