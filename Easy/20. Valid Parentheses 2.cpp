// https://leetcode.com/problems/valid-parentheses/

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> parentheses;

        map<char, int> mapping{
            {'(', 1},
            {')', 2},
            {'{', 3},
            {'}', 4},
            {'[', 5},
            {']', 6}};

        for (char &c : s)
        {
            if (mapping[c] % 2 != 0)
                parentheses.push(c);

            else
            {
                if (parentheses.empty() || mapping[c] != mapping[parentheses.top()] + 1)
                    return false;

                parentheses.pop();
            }
        }

        return parentheses.empty();
    }
};