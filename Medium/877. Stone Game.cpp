// https://leetcode.com/problems/stone-game/

class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        int alexStones = 0;
        int leeStones = 0;
        int i = 0;
        int j = piles.size() - 1;

        while (i < j)
        {
            if (piles[i] >= piles[j])
            {
                alexStones += piles[i];
                i++;
            }

            else
            {
                alexStones += piles[j];
                j--;
            }

            if (piles[j] >= piles[i])
            {
                leeStones += piles[i];
                i++;
            }

            else
            {
                leeStones += piles[j];
                j--;
            }
        }

        return alexStones > leeStones;
    }
};