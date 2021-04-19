// https://leetcode.com/problems/maximum-number-of-coins-you-can-get/

class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        int result = 0;
        int left = 0;
        int right = piles.size() - 1;
        int times = piles.size() / 3;

        sort(piles.begin(), piles.end());

        while (times--)
        {
            result += piles[right - 1];
            right -= 2;
            left += 1;
        }

        return result;
    }
};