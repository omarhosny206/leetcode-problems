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
        if (open == limit && closed == limit)
        {
            result.push_back(current);
            return;
        }

        if (open < limit)
            DFS(current + '(', open + 1, closed, limit);

        if (closed < open)
            DFS(current + ')', open, closed + 1, limit);
    }
};