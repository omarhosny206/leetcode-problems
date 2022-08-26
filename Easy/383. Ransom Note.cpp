
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> freq(26, 0);

        for (auto &c : magazine)
            freq[c - 'a']++;

        for (auto &c : ransomNote)
        {
            freq[c - 'a']--;
            
            if (freq[c - 'a'] < 0)
                return false;
        }

        return true;
    }
};