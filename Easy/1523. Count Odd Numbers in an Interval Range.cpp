
class Solution
{
public:
    int countOdds(int low, int high)
    {
        int result;

        if (low % 2 == 0 && high % 2 == 0)
            result = (high - low) / 2;

        else
            result = ((high - low) / 2) + 1;

        return result;
    }
};