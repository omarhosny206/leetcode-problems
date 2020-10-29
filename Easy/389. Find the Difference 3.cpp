// https://leetcode.com/problems/find-the-difference/

class Solution
{
public:
    char findTheDifference(string s, string t)
    {

        map<char, int> freq;

        for (char c : s)
            freq[c]++;

        for (char c : t)
        {
            if (freq[c] == 0)
                return c;
            freq[c]--;
        }

        return ' ';
    }
};