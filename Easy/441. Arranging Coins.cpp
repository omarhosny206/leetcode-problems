// https://leetcode.com/problems/arranging-coins/

class Solution
{
public:
    int arrangeCoins(int n)
    {
        if (n < 2)
            return n;

        int start = 0, end = n;
        while (start != end)
        {
            long long int middle = start + (end - start) / 2;
            long long int total_coins = (middle + 1) * middle / 2;
            if (total_coins == n)
                return middle;
            if (total_coins < n)
                start = middle + 1;
            else
                end = middle;
        }

        return start - 1;
    }
};
