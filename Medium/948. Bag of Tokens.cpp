// https://leetcode.com/problems/bag-of-tokens/

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        int score = 0;
        int i = 0;
        int j = tokens.size() - 1;

        sort(tokens.begin(), tokens.end());

        while (i <= j)
        {
            if (power >= tokens[i])
            {
                power -= tokens[i];
                score++;
                i++;
            }

            else if (score > 0 && j - i > 1 && (power + tokens[j]) >= tokens[i])
            {
                power += tokens[j];
                score--;
                j--;
            }

            else
                break;
        }

        return score;
    }
};