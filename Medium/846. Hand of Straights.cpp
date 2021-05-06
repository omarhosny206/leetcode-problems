// https://leetcode.com/problems/hand-of-straights/

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int W)
    {
        map<int, int> cards;

        for (int card : hand)
            cards[card]++;

        while (!cards.empty())
        {
            int firstCard = cards.begin()->first;

            for (int i = firstCard; i < firstCard + W; ++i)
            {
                if (cards.find(i) == cards.end())
                    return false;

                cards[i]--;

                if (cards[i] < 1)
                    cards.erase(i);
            }
        }

        return true;
    }
};