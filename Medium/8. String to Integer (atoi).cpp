// https://leetcode.com/problems/string-to-integer-atoi/

class Solution
{
public:
    int myAtoi(string str)
    {
        if (str.length() == 0)
            return 0;

        int result = 0;
        int sign = 1;
        int i = 0;

        while (i < str.length() && str[i] == ' ')
            i++;

        if (i < str.length() && str[i] == '+' || str[i] == '-')
            sign = (str[i++] == '-') ? -1 : 1;

        while (i < str.length() && str[i] >= '0' && str[i] <= '9')
        {

            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10))
                return (sign == 1) ? INT_MAX : INT_MIN;

            result = (result * 10) + (str[i++] - '0');
        }
        return result * sign;
    }
};