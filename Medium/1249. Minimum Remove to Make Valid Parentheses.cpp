// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        string result = "";
        int open = 0;

        for (char &c : s)
        {
            if (c == '(')
                open++;

            else if (c == ')')
            {
                if (open == 0)
                    c = '0';

                else
                    open--;
            }
        }

        for (int i = s.length() - 1; i >= 0; --i)
        {
            if (s[i] == '(' && open > 0)
                open--;

            else if (s[i] != '0')
                result += s[i];
        }

        reverse(result.begin(), result.end());
        return result;
    }
};