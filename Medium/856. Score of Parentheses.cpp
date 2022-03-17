// https://leetcode.com/problems/score-of-parentheses/

class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        int score = 0;
        int counter = 0;

        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(')
                counter++;

            else
            {
                counter--;

                if (s[i - 1] == '(')
                    score += pow(2, counter);
            }
        }

        return score;
    }
};