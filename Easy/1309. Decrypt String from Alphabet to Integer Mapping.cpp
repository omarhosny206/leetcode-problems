// https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/

class Solution
{
public:
    string freqAlphabets(string s)
    {
        string result = "";

        for (int i = s.length() - 1; i >= 0; --i)
        {
            if (s[i] == '#')
            {
                char letter = (s[i - 2] - '0') * 10 + s[i - 1] + 48;
                result += letter;
                i -= 2;
            }

            else
            {
                char letter = s[i] + 48;
                result += letter;
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};