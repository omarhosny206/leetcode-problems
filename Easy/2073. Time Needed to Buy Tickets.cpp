// https://leetcode.com/problems/time-needed-to-buy-tickets/

class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int result = 0;

        for (int i = 0; i < tickets.size(); ++i)
        {
            if (i <= k)
                result += min(tickets[k], tickets[i]);

            else
                result += min(tickets[k] - 1, tickets[i]);
        }

        return result;
    }
};