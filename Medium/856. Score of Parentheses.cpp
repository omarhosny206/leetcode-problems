// https://leetcode.com/problems/score-of-parentheses/

class Solution
{
public:
    int scoreOfParentheses(string S)
    {
        int score = 0;
        int counter = 0;

        for (int i = 0; i < S.length(); ++i)
        {
            if (S[i] == '(')
                counter++;

            else
            {
                counter--;
                if (S[i - 1] == '(')
                    score += pow(2, counter);
            }
        }

        return score;
    }
};