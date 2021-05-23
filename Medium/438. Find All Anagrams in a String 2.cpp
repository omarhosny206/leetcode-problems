// https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> result;
        unordered_map<int, int> freq;
        int i = 0;
        int counter = 0;

        for (char &c : p)
            freq[c]++;

        for (int j = 0; j < s.length(); ++j)
        {
            if (--freq[s[j]] >= 0)
                counter++;

            if (j - i + 1 == p.length())
            {
                if (counter == p.length())
                    result.push_back(i);

                if (++freq[s[i]] > 0)
                    counter--;

                i++;
            }
        }

        return result;
    }
};