// https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/

class Solution
{
public:
    int minCostToMoveChips(vector<int> &position)
    {
        int even_counter = 0;
        int odd_counter = 0;

        for (int pos : position)
        {
            if (pos % 2 == 0)
                even_counter++;
            else
                odd_counter++;
        }

        return min(even_counter, odd_counter);
    }
};