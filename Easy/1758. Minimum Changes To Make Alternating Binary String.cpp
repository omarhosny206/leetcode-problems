// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/

class Solution
{
public:
    int minOperations(string s)
    {
        int odd = 0;
        int even = 0;

        for (int i = 0; i < s.length(); ++i)
        {
            if ((i % 2 == 0 && s[i] == '1') || (i % 2 != 0 && s[i] == '0'))
            {
                even++;
            }

            if ((i % 2 == 0 && s[i] == '0') || (i % 2 != 0 && s[i] == '1'))
            {
                odd++;
            }
        }

        return min(odd, even);
    }
};