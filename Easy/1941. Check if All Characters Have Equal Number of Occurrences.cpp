// https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/

class Solution
{
public:
    bool areOccurrencesEqual(string s)
    {
        int current = 0;
        vector<int> freq(26);

        for (char &c : s)
            freq[c - 'a']++;

        for (int i = 0; i < freq.size(); ++i)
        {
            if (freq[i] > 0)
            {
                if (current != 0 && current != freq[i])
                    return false;

                current = freq[i];
            }
        }

        return true;
    }
};