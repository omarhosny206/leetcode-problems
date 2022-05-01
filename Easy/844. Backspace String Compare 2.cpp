// https://leetcode.com/problems/backspace-string-compare/

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> first;
        stack<char> second;

        for (char &c : s)
        {
            if (c != '#')
                first.push(c);

            else if (!first.empty())
                first.pop();
        }

        for (char &c : t)
        {
            if (c != '#')
                second.push(c);

            else if (!second.empty())
                second.pop();
        }

        return first == second;
    }
};