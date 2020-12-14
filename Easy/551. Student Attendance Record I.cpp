// https://leetcode.com/problems/student-attendance-record-i/

class Solution
{
public:
    bool checkRecord(string s)
    {
        int lateCounter = 0;
        int absenceCounter = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'P')
                lateCounter = 0;

            else if (s[i] == 'A')
            {
                lateCounter = 0;
                absenceCounter++;
                if (absenceCounter > 1)
                    return false;
            }

            else if (s[i] == 'L')
            {
                lateCounter++;
                if (lateCounter > 2)
                    return false;
            }
        }

        return true;
    }
};