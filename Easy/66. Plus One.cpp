// https://leetcode.com/problems/plus-one/

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 0;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            int sum = digits[i] + 1;
            digits[i] = sum % 10;
            carry = sum / 10;
            if (carry == 0)
                break;
        }

        if (carry != 0)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};