// https://leetcode.com/problems/permutation-in-string/

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> freq(26);
        int i = 0;
        int j = 0;
        int counter = 0;

        for (char &c : s1)
            freq[c - 'a']++;

        while (j < s2.length())
        {
            if (--freq[s2[j] - 'a'] >= 0)
                counter++;

            if (j - i + 1 == s1.length())
            {
                if (counter == s1.length())
                    return true;

                if (++freq[s2[i] - 'a'] > 0)
                    counter--;

                i++;
            }

            j++;
        }

        return false;
    }
};