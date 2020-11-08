// https://leetcode.com/problems/backspace-string-compare/

class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        string new_s = stringBuilder(S);
        string new_t = stringBuilder(T);
        return new_s == new_t;
    }

    string stringBuilder(string text)
    {
        string result = "";
        stack<char> text_stack;

        for (char c : text)
        {
            if (c != '#')
                text_stack.push(c);
            else if (!text_stack.empty())
                text_stack.pop();
        }

        while (!text_stack.empty())
        {
            result += text_stack.top();
            text_stack.pop();
        }

        return result;
    }
};