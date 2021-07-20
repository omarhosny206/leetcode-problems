// https://leetcode.com/problems/check-if-the-sentence-is-pangram/

class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        int counter = 0;
        int englishLetters = 26;
        vector<int> freq(26);

        if (sentence.length() < englishLetters)
            return false;

        for (char &c : sentence)
        {
            freq[c - 'a']++;

            counter += (freq[c - 'a'] == 1) ? 1 : 0;
        }

        return counter == englishLetters;
    }
};