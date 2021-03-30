// https://leetcode.com/problems/valid-parentheses/

class Solution
{
public:
    bool isValid(string s)
    {

        map<char, int> mapping{
            {'(', 1},
            {')', 2},
            {'{', 3},
            {'}', 4},
            {'[', 5},
            {']', 6}};

        stack<char> parentheses_stack;
        for (char c : s)
        {
            if (mapping[c] % 2 != 0)
                parentheses_stack.push(c);

            else
            {
                if (parentheses_stack.empty() || mapping[c] != mapping[parentheses_stack.top()] + 1)
                    return false;
                parentheses_stack.pop();
            }
        }

        return parentheses_stack.size() == 0;
    }
};