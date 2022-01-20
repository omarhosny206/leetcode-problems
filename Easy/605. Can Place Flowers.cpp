// https://leetcode.com/problems/can-place-flowers/

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        if (n == 0)
            return true;

        int counter = 0;
        int i = 0;

        while (i < flowerbed.size())
        {

            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0))
            {
                flowerbed[i] = 1;
                counter++;

                if (counter == n)
                    return true;
            }

            i++;
        }

        return false;
    }
};