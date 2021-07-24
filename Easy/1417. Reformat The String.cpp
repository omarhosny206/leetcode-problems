// https://leetcode.com/problems/reformat-the-string/

class Solution
{
public:
    string reformat(string s)
    {
        string result = "";
        string digits = getDigits(s);
        string letters = getLetters(s);

        if (!isOk(digits, letters))
            return result;

        if (digits.length() > letters.length())
        {
            result = digits[0];
            result += Reformat(digits, letters, 1, 0, 2 * letters.length(), 1);
        }

        else if (digits.length() < letters.length())
        {
            result = letters[0];
            result += Reformat(digits, letters, 0, 1, 2 * digits.length(), 0);
        }

        else
            result += Reformat(digits, letters, 0, 0, 2 * digits.length(), 0);

        return result;
    }

    string Reformat(string &digits, string &letters, int i, int j, int totalSize, int sign)
    {
        string result = "";

        while (totalSize--)
        {
            result += (sign == 0) ? digits[i++] : letters[j++];
            sign = !sign;
        }

        return result;
    }

    string getDigits(string &s)
    {
        string result = "";

        for (char &c : s)
            if (isdigit(c))
                result += c;

        return result;
    }

    string getLetters(string &s)
    {
        string result = "";

        for (char &c : s)
            if (isalpha(c))
                result += c;

        return result;
    }

    bool isOk(string &digits, string &letters)
    {
        return abs((int)(digits.length() - letters.length())) <= 1;
    }
};