// https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/

class Solution
{
public:
    bool areOccurrencesEqual(string s)
    {
        int current = 0;
        unordered_map<char, int> freq;

        for (char &c : s)
            freq[c]++;

        for (char &c : s)
        {
            if (freq[c] > 0)
            {
                if (current != 0 && current != freq[c])
                    return false;

                current = freq[c];
            }
        }

        return true;
    }
};