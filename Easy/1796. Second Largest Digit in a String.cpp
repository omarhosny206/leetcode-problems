// https://leetcode.com/problems/second-largest-digit-in-a-string/

class Solution
{
public:
    int secondHighest(string s)
    {
        int firstMax = -1;
        int secondMax = -1;

        for (char c : s)
        {
            if (c >= '0' && c <= '9')
            {
                int number = (c - '0');
                if (number > firstMax)
                {
                    secondMax = firstMax;
                    firstMax = number;
                }

                else if (number < firstMax && number > secondMax)
                    secondMax = number;
            }
        }

        return secondMax == -1 ? -1 : secondMax;
    }
};