// https://leetcode.com/problems/koko-eating-bananas/

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        if (piles.size() == 0)
            return 0;

        return binarySearch(piles, h);
    }

    int binarySearch(vector<int> &piles, int h)
    {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low < high)
        {
            int middle = low + (high - low) / 2;

            if (isPossible(piles, h, middle) == true)
                high = middle;

            else
                low = middle + 1;
        }

        return low;
    }

    bool isPossible(vector<int> &piles, int h, int middle)
    {
        int sum = 0;
        for (int pile : piles)
            sum += (pile / middle) + (pile % middle == 0 ? 0 : 1);

        return sum <= h;
    }
};