// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

class Solution
{
public:
    int minAddToMakeValid(string S)
    {
        int open = 0;
        int closed = 0;

        for (char c : S)
        {
            if (c == '(')
                open++;

            else
            {
                if (open > 0)
                    open--;
                else
                    closed++;
            }
        }

        return open + closed;
    }
};