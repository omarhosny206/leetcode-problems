// https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/

class Solution
{
public:
    int countGoodSubstrings(string s)
    {
        int result = 0;
        vector<int> freq(26);
        int i = 0;
        int j = 0;
        int counter = 0;

        while (j < s.length())
        {
            if (++freq[s[j] - 'a'] > 1)
                counter++;

            if (j - i + 1 == 3)
            {
                if (counter == 0)
                    result++;

                if (--freq[s[i] - 'a'] > 0)
                    counter--;

                i++;
            }

            j++;
        }

        return result;
    }
};