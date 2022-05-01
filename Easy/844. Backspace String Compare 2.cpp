// https://leetcode.com/problems/backspace-string-compare/

class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        stack<char> first;
        stack<char> second;

        for (char c : S)
        {
            if (c != '#')
                first.push(c);

            else if (!first.empty())
                first.pop();
        }

        for (char c : T)
        {
            if (c != '#')
                second.push(c);

            else if (!second.empty())
                second.pop();
        }

        return first == second;
    }
};