// https://leetcode.com/problems/remove-k-digits/

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (k == num.length())
            return "0";

        string result;

        stack<int> values;
        int i = 0;

        while (i < num.length())
        {
            while (!values.empty() && k > 0 && values.top() > num[i])
            {
                values.pop();
                k--;
            }

            if (!values.empty() || num[i] != '0')
                values.push(num[i]);

            i++;
        }

        while (!values.empty() && k > 0)
        {
            values.pop();
            k--;
        }

        if (values.empty())
            return "0";

        while (!values.empty())
        {
            result += values.top();
            values.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};