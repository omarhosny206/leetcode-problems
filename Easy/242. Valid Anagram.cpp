// https://leetcode.com/problems/valid-anagram/

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        vector<int> table(26, 0);
        for (char c : s)
            table[c - 'a']++;
        for (char c : t)
        {
            table[c - 'a']--;
            if (table[c - 'a'] < 0)
                return false;
        }
        return true;
    }
};