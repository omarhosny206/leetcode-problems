// https://leetcode.com/problems/three-consecutive-odds/

class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int counter = 0;
        for (int num : arr)
        {

            if (counter == 3)
                break;

            if (num % 2 != 0)
                counter++;

            else
                counter = 0;
        }

        return counter == 3;
    }
};