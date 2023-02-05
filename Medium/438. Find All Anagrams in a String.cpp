class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> result;

        vector<int> freq(26);
        int i = 0;
        int j = 0;
        int counter = 0;

        for (char &c : p)
            freq[c - 'a']++;

        while (j < s.length())
        {
            if (--freq[s[j] - 'a'] >= 0)
                counter++;

            int windowSize = j - i + 1;

            if (windowSize == p.length())
            {
                if (counter == p.length())
                    result.push_back(i);

                if (++freq[s[i] - 'a'] > 0)
                    counter--;

                i++;
            }

            ++j;
        }

        return result;
    }
};