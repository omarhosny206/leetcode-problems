// https://leetcode.com/problems/time-needed-to-buy-tickets/

class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int result = 0;

        while (tickets[k] > 0)
        {
            int i = 0;

            while (i < tickets.size() && tickets[k])
            {
                tickets[i]--;

                if (tickets[i] >= 0)
                    result++;

                i++;
            }
        }

        return result;
    }
};