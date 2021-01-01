// https://leetcode.com/problems/divisor-game/

class Solution
{
public:
    bool divisorGame(int N)
    {
        int i = 1;
        int counter = 1;

        while (N > 0)
        {
            if (N % i == 0)
            {
                N -= i;
                counter++;
                i = 1;
            }
            else
                i++;
        }

        return (counter % 2 == 0) ? false : true;
    }
};