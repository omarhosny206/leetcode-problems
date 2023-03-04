// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        vector<int> freq(26);
        int i = 0;
        int j = 0;
        int counter = 0;

        for (char &c : needle)
            freq[c - 'a']++;

        while (j < haystack.length())
        {
            if (--freq[haystack[j] - 'a'] >= 0)
                counter++;

            int windowSize = j - i + 1;

            if (windowSize == needle.length())
            {
                if (counter == needle.length() && haystack.substr(i, j - i + 1) == needle)
                    return i;

                if (++freq[haystack[i] - 'a'] > 0)
                    counter--;

                i++;
            }

            j++;
        }

        return -1;
    }
};