class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> freq;
        for (char c : magazine)
            freq[c]++;

        for (char c : ransomNote)
        {
            if (freq.find(c) == freq.end() || freq[c] == 0)
                return false;
            freq[c]--;
        }

        return true;
    }
};