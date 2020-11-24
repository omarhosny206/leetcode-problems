// https://leetcode.com/problems/count-sorted-vowel-strings/

class Solution
{
public:
    int countVowelStrings(int n)
    {
        int a = 1, e = 1, i = 1, o = 1, u = 1;

        while (n-- > 1)
        {
            o += u;
            i += o;
            e += i;
            a += e;
        }

        return (a + e + i + o + u);
    }
};