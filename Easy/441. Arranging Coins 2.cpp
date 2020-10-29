// https://leetcode.com/problems/arranging-coins/

class Solution
{
public:
    int arrangeCoins(int n)
    {
        int result = 0;
        int coins = 0;
        while (n >= 0)
        {
            coins++;
            n -= coins;
            result++;
        }
        return result - 1;
    }
};