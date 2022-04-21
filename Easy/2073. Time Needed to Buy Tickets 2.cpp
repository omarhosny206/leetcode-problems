// https://leetcode.com/problems/time-needed-to-buy-tickets/

class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int result = 0;

        for (int i = 0; i < tickets.size(); ++i)
            result += min(tickets[k] - (i > k), tickets[i]);

        return result;
    }
};