// https://leetcode.com/problems/number-of-valid-clock-times/

class Solution
{
public:
    int countTime(string time)
    {
        string hours = time.substr(0, 2);
        string minutes = time.substr(3, 4);
        int hoursValue = 0;
        int minutesValue = 0;

        if (hours == "??" && minutes == "??")
            return 24 * 60;

        if (hours == "??")
            hoursValue = 24;

        else if (hours[0] == '?')
            hoursValue = (hours[1] - '0') <= 3 ? 3 : 2;

        else if (hours[1] == '?')
            hoursValue = (hours[0] - '0') < 2 ? 10 : 4;

        if (minutes == "??")
            minutesValue = 60;

        else if (minutes[0] == '?')
            minutesValue = 6;

        else if (minutes[1] == '?')
            minutesValue = 10;

        if (hoursValue == 0 && minutesValue == 0)
            return 1;

        if (hoursValue == 0 || minutesValue == 0)
            return hoursValue + minutesValue;

        return hoursValue * minutesValue;
    }
};