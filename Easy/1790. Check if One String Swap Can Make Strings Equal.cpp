// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/

class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        if (s1 == s2)
            return true;

        int counter = 0;
        string first = "";
        string second = "";

        for (int i = 0; i < s1.length(); ++i)
        {
            if (s1[i] != s2[i])
            {
                counter++;
                if (counter > 2)
                    return false;

                first += s1[i];
                second += s2[i];
            }
        }

        reverse(first.begin(), first.end());
        return first == second;
    }
};