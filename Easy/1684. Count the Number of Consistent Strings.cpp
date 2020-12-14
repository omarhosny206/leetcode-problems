// https://leetcode.com/problems/count-the-number-of-consistent-strings/

class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        int result = 0;

        bool freq[26] = {};
        for (char c : allowed)
            freq[(c - 'a')] = true;

        for (string word : words)
        {
            int charCounter = 0;

            for (char c : word)
                charCounter = (freq[c - 'a'] == true) ? charCounter + 1 : charCounter;

            if (charCounter == word.length())
                result++;
        }

        return result;
    }
};