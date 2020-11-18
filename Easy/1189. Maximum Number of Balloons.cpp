// https://leetcode.com/problems/maximum-number-of-balloons/

class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        int b = 0;
        int a = 0;
        int l = 0;
        int o = 0;
        int n = 0;

        for (char c : text)
        {
            if (c == 'b')
                b++;
            if (c == 'a')
                a++;
            if (c == 'l')
                l++;
            if (c == 'o')
                o++;
            if (c == 'n')
                n++;
        }

        l /= 2;
        o /= 2;

        int MIN = min({b, a, l, o, n});
        return MIN;
    }
};