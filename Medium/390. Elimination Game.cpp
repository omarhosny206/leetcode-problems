// https://leetcode.com/problems/elimination-game/

class Solution
{
public:
    int lastRemaining(int n)
    {
        int answer = 1;
        int step = 1;
        int remaining = n;
        bool direction = true;

        while (remaining > 1)
        {
            if (direction == true || remaining % 2 == 1)
                answer += step;

            remaining /= 2;
            step *= 2;
            direction = !direction;
        }

        return answer;
    }
};