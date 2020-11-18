// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/

class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        int result = 0;

        unordered_map<char, int> freq;
        for (char c : chars)
            freq[c]++;

        for (string current : words)
        {
            unordered_map<char, int> freq_checker;
            bool canBeFormed = true;

            for (char c : current)
            {
                freq_checker[c]++;
                if (freq_checker[c] > freq[c])
                {
                    canBeFormed = false;
                    break;
                }
            }

            result = (canBeFormed) ? result + current.length() : result;
        }

        return result;
    }
};