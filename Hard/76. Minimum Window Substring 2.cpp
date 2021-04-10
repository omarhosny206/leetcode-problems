// https://leetcode.com/problems/minimum-window-substring/

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int start = -1;
        int minSize = INT_MAX;
        unordered_map<char, int> freq;
        int i = 0;
        int counter = 0;

        for (char c : t)
            freq[c]++;

        for (int j = 0; j < s.length(); ++j)
        {
            if (--freq[s[j]] >= 0)
                counter++;

            while (counter == t.length())
            {
                if (minSize > j - i + 1)
                {
                    minSize = j - i + 1;
                    start = i;
                }

                if (++freq[s[i]] > 0)
                    counter--;

                ++i;
            }
        }

        return start == -1 ? "" : s.substr(start, minSize);
    }
};