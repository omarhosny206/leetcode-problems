// https://leetcode.com/problems/minimum-window-substring/

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t.length() > s.length())
            return "";

        string result = "";
        unordered_map<char, int> freq;

        int start = -1;
        int minWindowSize = INT_MAX;
        int i = 0;
        int j = 0;
        int counter = 0;

        for (char &c : t)
            freq[c]++;

        while (j < s.length())
        {
            if (--freq[s[j]] >= 0)
                counter++;

            while (counter == t.length())
            {
                int currentWindowSize = j - i + 1;
                if (currentWindowSize < minWindowSize)
                {
                    minWindowSize = currentWindowSize;
                    start = i;
                }

                if (++freq[s[i]] > 0)
                    counter--;

                i++;
            }

            j++;
        }

        if (start == -1)
            return "";

        result = s.substr(start, minWindowSize);
        return result;
    }
};