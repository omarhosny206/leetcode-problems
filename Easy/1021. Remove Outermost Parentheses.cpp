// https://leetcode.com/problems/remove-outermost-parentheses/

class Solution
{
public:
    string removeOuterParentheses(string S)
    {
        string answer;
        stack<char> Parentheses;

        for (char c : S)
        {
            if (c == ')')
                Parentheses.pop();

            if (!Parentheses.empty())
                answer += c;

            if (c == '(')
                Parentheses.push(c);
        }

        return answer;
    }
};