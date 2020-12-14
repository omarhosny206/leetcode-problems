// https://leetcode.com/problems/count-the-number-of-consistent-strings/

class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        int result = 0;

        map<char, int> freq;
        for (char c : allowed)
            freq[c]++;

        for (string word : words)
        {
            int charCounter = 0;

            for (char c : word)
                charCounter = (freq[c] > 0) ? charCounter + 1 : charCounter;

            if (charCounter == word.length())
                result++;
        }

        return result;
    }
};