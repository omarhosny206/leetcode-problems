// https://leetcode.com/problems/check-if-the-sentence-is-pangram/

class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        vector<int> freq(26);

        if (sentence.length() < 26)
            return false;

        for (char &c : sentence)
            freq[c - 'a']++;

        for (int i = 0; i < freq.size(); ++i)
            if (freq[i] == 0)
                return false;

        return true;
    }
};