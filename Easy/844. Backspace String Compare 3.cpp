// https://leetcode.com/problems/backspace-string-compare/

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        string first = buildString(s);
        string second = buildString(t);
        return first == second;
    }

    string buildString(string &text)
    {
        string result = "";
        stack<char> letters;

        for (char c : text)
        {
            if (c != '#')
                letters.push(c);

            else if (!letters.empty())
                letters.pop();
        }

        while (!letters.empty())
        {
            result += letters.top();
            letters.pop();
        }

        return result;
    }
};