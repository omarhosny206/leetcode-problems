// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

class Solution
{
public:
    string reverseParentheses(string s)
    {
        string result = "";
        stack<int> indices;

        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(')
                indices.push(i);

            else if (s[i] == ')')
            {
                int start = indices.top();
                indices.pop();
                Reverse(s, start + 1, i - 1);
            }
        }

        result = removeParentheses(s);
        return result;
    }

    void Reverse(string &s, int i, int j)
    {
        while (i <= j)
        {
            char temp = s[i];
            s[i++] = s[j];
            s[j--] = temp;
        }
    }

    string removeParentheses(string &s)
    {
        string result = "";

        for (char &c : s)
            if (c != '(' && c != ')')
                result += c;

        return result;
    }
};