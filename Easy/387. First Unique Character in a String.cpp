// https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution
{
public:
    int firstUniqChar(string s)
    {
        map<char, int> freq;
        int i = 0;

        for (char c : s)
            freq[c]++;

        for (char c : s)
        {
            if (freq[c] == 1)
                return i;
            i++;
        }

        return -1;
    }
};