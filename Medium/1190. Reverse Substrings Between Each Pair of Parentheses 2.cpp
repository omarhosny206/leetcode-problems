// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

class Solution
{
public:
    string reverseParentheses(string s)
    {
        int i = 0;
        string result = DFS(s, i);
        return result;
    }

    string DFS(string &s, int &i)
    {
        string result = "";

        while (i < s.length() && s[i] != ')')
        {
            if (s[i] == '(')
            {
                i++;
                result += DFS(s, i);
            }

            else
                result += s[i];

            i++;
        }

        if (i < s.length() && s[i] == ')')
            reverse(result.begin(), result.end());

        return result;
    }
};