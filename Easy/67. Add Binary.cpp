// https://leetcode.com/problems/add-binary/

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int sum = 0;
        int carry = 0;
        while (i >= 0 || j >= 0)
        {
            sum = carry;
            if (i >= 0)
                sum += a[i--] - '0';

            if (j >= 0)
                sum += b[j--] - '0';

            result.insert(0, to_string(sum % 2));
            carry = sum / 2;
        }
        if (carry > 0)
            result.insert(0, "1");
        return result;
    }
};