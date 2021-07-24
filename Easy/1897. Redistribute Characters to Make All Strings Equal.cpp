// https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/

class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        vector<int> freq(26);

        for (string &word : words)
            for (char &c : word)
                freq[c - 'a']++;

        for (int i = 0; i < freq.size(); ++i)
            if (freq[i] % words.size() != 0)
                return false;

        return true;
    }
};