// https://leetcode.com/problems/generate-parentheses/

class Solution
{
    vector<string> result;

public:
    vector<string> generateParenthesis(int n)
    {
        DFS("", n, n);
        return result;
    }

    void DFS(string current, int open, int closed)
    {

        if (open == 0 && closed == 0)
        {
            result.push_back(current);
            return;
        }

        if (open > 0)
            DFS(current + '(', open - 1, closed);

        if (closed > open)
            DFS(current + ')', open, closed - 1);
    }
};