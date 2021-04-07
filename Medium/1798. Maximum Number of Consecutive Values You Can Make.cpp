// https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/

class Solution
{
public:
    int getMaximumConsecutive(vector<int> &coins)
    {
        int result = 1;

        sort(coins.begin(), coins.end());

        for (int coin : coins)
        {
            if (result >= coin)
                result += coin;

            else
                break;
        }

        return result;
    }
};