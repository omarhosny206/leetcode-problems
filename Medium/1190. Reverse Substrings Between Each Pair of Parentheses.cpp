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
                string temp = DFS(s, i);
                reverse(temp.begin(), temp.end());
                result += temp;
            }

            else
                result += s[i];

            i++;
        }

        return result;
    }
};