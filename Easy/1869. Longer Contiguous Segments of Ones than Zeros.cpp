// https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/

class Solution
{
public:
    bool checkZeroOnes(string s)
    {
        return hasGreaterSegment(s);
    }

    bool hasGreaterSegment(string s)
    {
        int first = 0;
        int second = 0;
        int firstCounter = 0;
        int secondCounter = 0;

        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '1')
            {
                firstCounter++;
                second = max(second, secondCounter);
                secondCounter = 0;
            }

            else
            {
                secondCounter++;
                first = max(first, firstCounter);
                firstCounter = 0;
            }
        }

        first = max(first, firstCounter);
        second = max(second, secondCounter);

        return first > second;
    }
};