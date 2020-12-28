// https://leetcode.com/problems/thousand-separator/

class Solution
{
public:
    string thousandSeparator(int n)
    {
        string result = "";
        string number = to_string(n);
        int i = number.length() - 1;
        int j = 0;

        while (i >= 0)
        {
            if (j % 3 == 0 && j != 0)
                result += '.';

            result += number[i];
            i--;
            j++;
        }

        Reverse(result);
        return result;
    }

    void Reverse(string &result)
    {
        int i = 0;
        int j = result.length() - 1;

        while (i < j)
        {
            char temp = result[i];
            result[i++] = result[j];
            result[j--] = temp;
        }
    }
};