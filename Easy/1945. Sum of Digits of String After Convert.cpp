// https://leetcode.com/problems/sum-of-digits-of-string-after-convert/

class Solution
{
public:
    int getLucky(string s, int k)
    {
        int result = 0;
        string digits = getDigits(s);

        while (k--)
        {
            result = ProcessDigits(digits);
            digits = to_string(result);
        }

        return result;
    }

    int ProcessDigits(string &digits)
    {
        int result = 0;

        for (char &c : digits)
            result += (c - '0');

        return result;
    }

    string getDigits(string &s)
    {
        string result = "";

        for (char &c : s)
            result += to_string((c - 'a') + 1);

        return result;
    }
};