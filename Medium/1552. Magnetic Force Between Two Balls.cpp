// https://leetcode.com/problems/magnetic-force-between-two-balls/

class Solution
{
public:
    int maxDistance(vector<int> &position, int m)
    {
        sort(position.begin(), position.end());

        int left = 1, right = position[position.size() - 1], answer = -1;

        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            if (countBalls(position, m, middle) >= m)
            {
                answer = middle;
                left = middle + 1;
            }
            else
                right = middle - 1;
        }

        return answer;
    }

    int countBalls(vector<int> &position, int m, int middle)
    {
        int numBalls = 0;
        int lastBallPosition = -1;
        for (int i = 0; i < position.size(); ++i)
        {
            if (position[i] - lastBallPosition >= middle || lastBallPosition == -1)
            {
                lastBallPosition = position[i];
                numBalls++;
            }
        }

        return numBalls;
    }
};