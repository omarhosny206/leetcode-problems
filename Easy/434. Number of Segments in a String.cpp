// https://leetcode.com/problems/number-of-segments-in-a-string/

class Solution
{
public:
    int countSegments(string s)
    {
        if (s.length() == 0)
            return 0;

        bool isSegmentBegining = false;
        int numSegments = 0;

        for (char c : s)
        {
            if (c != ' ' && isSegmentBegining == false)
            {
                numSegments++;
                isSegmentBegining = true;
            }

            if (c == ' ')
                isSegmentBegining = false;
        }

        return numSegments;
    }
};