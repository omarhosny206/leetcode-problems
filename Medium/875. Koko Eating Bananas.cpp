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

            if (isPossible(piles, middle, h))
                high = middle;

            else
                low = middle + 1;
        }

        return low;
    }

    bool isPossible(vector<int> &piles, int eatingRate, int h)
    {
        int hours = 0;

        for (int &pile : piles)
            hours += (pile / eatingRate) + (pile % eatingRate == 0 ? 0 : 1);

        return hours <= h;
    }
};