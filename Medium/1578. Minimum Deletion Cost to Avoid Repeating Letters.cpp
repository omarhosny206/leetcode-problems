// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int result = 0;
        int i = 0;

        while (i < colors.size())
        {
            if (i < colors.size() - 1 && colors[i] == colors[i + 1])
            {
                int sum = 0;
                int maxValue = INT_MIN;

                while (i < colors.size() - 1 && colors[i] == colors[i + 1])
                {
                    sum += neededTime[i];
                    maxValue = max(maxValue, neededTime[i]);
                    i++;
                }

                sum += neededTime[i];
                maxValue = max(maxValue, neededTime[i]);

                result += (sum - maxValue);
            }

            i++;
        }

        return result;
    }
};