// https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/

class Solution
{
public:
    bool checkZeroOnes(string s)
    {
        int first = getLongestSegment(s, '1');
        int second = getLongestSegment(s, '0');
        return first > second;
    }

    int getLongestSegment(string s, char target)
    {
        int result = INT_MIN;
        int counter = 0;

        for (int i = 0; i < s.length(); ++i)
        {
            if (target == s[i])
                counter++;

            else
            {
                result = max(result, counter);
                counter = 0;
            }
        }

        result = max(result, counter);
        return result;
    }
};