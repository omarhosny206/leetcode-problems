// https://leetcode.com/problems/multiply-strings/

class Solution
{
public:
    string multiply(string num1, string num2)
    {

        if (num1[0] == '0' || num2[0] == '0')
            return "0";

        vector<int> vals(num1.length() + num2.length());

        for (int i = num1.length() - 1; i >= 0; --i)
        {
            for (int j = num2.length() - 1; j >= 0; --j)
            {
                int multi = (num1[i] - '0') * (num2[j] - '0');
                int sum = vals[i + j + 1] + multi;
                vals[i + j] += sum / 10;
                vals[i + j + 1] = sum % 10;
            }
        }

        string result = "";
        for (int n : vals)
            if (result.length() != 0 || n != 0)
                result += to_string(n);

        return result;
    }
};