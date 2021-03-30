// https://leetcode.com/problems/valid-parentheses/

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> parentheses;
        for (int i = 0; i < s.length(); ++i)
        {
            if (isOpenParenthese(s[i]))
                parentheses.push(s[i]);

            else
            {
                if (parentheses.empty() || s[i] != getPair(parentheses.top()))
                    return false;

                parentheses.pop();
            }
        }

        return parentheses.empty();
    }

    bool isOpenParenthese(char c)
    {
        return c == '(' || c == '{' || c == '[';
    }

    char getPair(char c)
    {
        if (c == '(')
            return ')';

        else if (c == '{')
            return '}';

        return ']';
    }
};