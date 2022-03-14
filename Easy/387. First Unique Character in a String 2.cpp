// https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> freq;

        for (int i = 0; i < s.length(); ++i)
            freq[s[i]]++;

        for (int i = 0; i < s.length(); ++i)
            if (freq[s[i]] == 1)
                return i;

        return -1;
    }
};