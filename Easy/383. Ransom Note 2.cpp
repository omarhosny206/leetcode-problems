// https://leetcode.com/problems/ransom-note/

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> freq;

        for (char &c : magazine)
            freq[c]++;

        for (char &c : ransomNote)
        {
            freq[c]--;

            if (freq[c] < 0)
                return false;
        }

        return true;
    }
};