// https://leetcode.com/problems/sqrtx/

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x < 2)
            return x;

        long long low = 1;
        long long high = x;
        while (low <= high)
        {
            long long middle = (high + low) / 2;
            if (middle * middle == x)
                return middle;
            if (middle * middle > x)
                high = middle - 1;
            else
                low = middle + 1;
        }

        return min(low, high);
    }
};