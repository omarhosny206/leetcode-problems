// https://leetcode.com/problems/generate-parentheses/

class Solution
{
    vector<string> result;

public:
    vector<string> generateParenthesis(int n)
    {
        DFS("", 0, 0, n);
        return result;
    }

    void DFS(string current, int open, int closed, int limit)
    {
        if (closed > open)
            return;

        if (open > limit)
            return;

        if (open == limit && closed == limit)
        {
            result.push_back(current);
            return;
        }

        DFS(current + '(', open + 1, closed, limit);
        DFS(current + ')', open, closed + 1, limit);
    }
};