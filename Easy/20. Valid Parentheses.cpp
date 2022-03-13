// https://leetcode.com/problems/valid-parentheses/

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> parentheses;

        for (char &c : s)
        {
            if (isOpenParenthese(c))
                parentheses.push(c);

            else
            {
                if (parentheses.empty() || parentheses.top() != getPair(c))
                    return false;

                parentheses.pop();
            }
        }

        return parentheses.empty();
    }

    bool isOpenParenthese(char parenthese)
    {
        return parenthese == '(' || parenthese == '{' || parenthese == '[';
    }

    char getPair(char parenthese)
    {
        if (parenthese == ')')
            return '(';

        else if (parenthese == '}')
            return '{';

        return '[';
    }
};