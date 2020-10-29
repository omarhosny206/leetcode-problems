// https://leetcode.com/problems/count-number-of-teams/

class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int i, j, k;
        int teams = 0;

        for (j = 1; j < rating.size() - 1; j++)
        {
            int left_side_smaller = 0;
            int left_side_bigger = 0;
            int right_side_smaller = 0;
            int right_side_bigger = 0;

            for (i = 0; i < j; i++)
            {
                if (rating[i] < rating[j])
                {
                    left_side_smaller++;
                }
                else
                {
                    left_side_bigger++;
                }
            }

            for (k = j + 1; k < rating.size(); k++)
            {
                if (rating[k] < rating[j])
                {

                    right_side_smaller++;
                }
                else
                {
                    right_side_bigger++;
                }
            }

            teams += (left_side_smaller * right_side_bigger +
                      left_side_bigger * right_side_smaller);
        }

        return teams;
    }
};