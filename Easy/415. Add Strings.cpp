// https://leetcode.com/problems/add-strings/

class Solution
{
public:
    string addStrings(string num1, string num2)
    {

        int i = num1.size() - 1;
        int j = num2.size() - 1;
        string result = "";
        int carry = 0;
        int sum = 0;

        while (i >= 0 || j >= 0)
        {
            sum = carry;

            if (i >= 0)
                sum += num1[i] - '0';

            if (j >= 0)
                sum += num2[j] - '0';

            result += to_string(sum % 10);
            carry = sum / 10;
            i--;
            j--;
        }

        if (carry != 0)
            result += to_string(carry);

        reverse(result.begin(), result.end());
        return result;
    }
};