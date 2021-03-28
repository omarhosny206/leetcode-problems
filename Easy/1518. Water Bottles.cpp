// https://leetcode.com/problems/water-bottles/

class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int answer = 0;
        int numEmptyBottles = 0;

        while (numBottles != 0)
        {
            answer += numBottles;
            numEmptyBottles += numBottles;
            numBottles = numEmptyBottles / numExchange;
            numEmptyBottles -= numBottles * numExchange;
        }

        return answer;
    }
};