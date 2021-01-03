// https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/

class Solution
{
public:
    char findKthBit(int n, int k)
    {
        string binary = "0";

        for (int i = 2; i <= n; ++i)
        {
            string term = Reverse(Invert(binary));
            binary = binary + "1" + term;
        }

        return binary[k - 1];
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