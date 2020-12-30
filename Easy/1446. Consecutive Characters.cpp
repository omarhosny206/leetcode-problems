// https://leetcode.com/problems/consecutive-characters/

class Solution
{
public:
    int maxPower(string s)
    {
        int result = 0;
        int counter = 1;

        for (int i = 0; i < s.length() - 1; ++i)
        {
            if (s[i] == s[i + 1])
                counter++;

            else
            {
                result = max(result, counter);
                counter = 1;
            }
        }

        result = max(result, counter);
        return result;
    }
};