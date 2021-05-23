// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int result = 0;
        vector<int> freq(3);
        int i = 0;
        int counter = 0;

        for (int j = 0; j < s.length(); ++j)
        {
            if (++freq[s[j] - 'a'] == 1)
                counter++;

            while (counter == 3)
            {
                if (--freq[s[i] - 'a'] == 0)
                    counter--;

                i++;
            }

            result += i;
        }

        return result;
    }
};