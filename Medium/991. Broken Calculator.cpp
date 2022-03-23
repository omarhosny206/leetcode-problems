
class Solution
{
public:
    int brokenCalc(int startValue, int target)
    {
        int result = 0;

        while (startValue < target)
        {
            if (target % 2 == 0)
                target /= 2;

            else
                target++;

            result++;
        }

        return result + startValue - target;
    }
};