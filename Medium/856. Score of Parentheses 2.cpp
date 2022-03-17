// https://leetcode.com/problems/score-of-parentheses/

class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        int score = 0;
        stack<int> current;

        for (char &c : s)
        {
            if (c == '(')
            {
                current.push(score);
                score = 0;
            }

            else
            {
                score = current.top() + max(score * 2, 1);
                current.pop();
            }
        }

        return score;
    }
};