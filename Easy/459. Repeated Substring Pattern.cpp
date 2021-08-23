// https://leetcode.com/problems/repeated-substring-pattern/

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int length = s.length();

        for (int i = length / 2; i >= 1; --i)
        {
            if (length % i == 0)
            {
                string current = "";
                string substring = s.substr(0, i);

                for (int j = 0; j < length / i; ++j)
                    current += substring;

                if (current == s)
                    return true;
            }
        }

        return false;
    }
};