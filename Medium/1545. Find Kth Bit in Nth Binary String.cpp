// https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/

class Solution
{
public:
    char findKthBit(int n, int k)
    {
        string answer = binaryBuilder(n);

        return answer[k - 1];
    }

    string binaryBuilder(int number)
    {
        if (number == 1)
            return "0";

        string previous = binaryBuilder(number - 1);
        return previous + "1" + Reverse(Invert(previous));
    }

    string Reverse(string number)
    {
        int i = 0;
        int j = number.length() - 1;

        while (i < j)
        {
            char temp = number[i];
            number[i++] = number[j];
            number[j--] = temp;
        }

        return number;
    }

    string Invert(string number)
    {
        for (int i = 0; i < number.length(); ++i)
            number[i] = (number[i] == '0') ? '1' : '0';

        return number;
    }
};