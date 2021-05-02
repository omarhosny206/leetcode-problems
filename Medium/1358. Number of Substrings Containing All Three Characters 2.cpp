// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int result = 0;
        map<char, int> freq;

        int counter = 0;
        int i = 0;

        for (int j = 0; j < s.length(); ++j)
        {
            if (++freq[s[j]] == 1)
                counter++;

            while (counter == 3)
            {
                if (--freq[s[i]] == 0)
                    counter--;

                i++;
            }

            result += i;
        }

        return result;
    }
};