// https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int result = 0;
        priority_queue<int, vector<int>, greater<int>> values;
        int i = 0;

        while (i < colors.size())
        {
            if (i < colors.size() - 1 && colors[i] == colors[i + 1])
            {
                while (i < colors.size() - 1 && colors[i] == colors[i + 1])
                {
                    values.push(neededTime[i]);
                    i++;
                }

                values.push(neededTime[i]);
            }

            while (values.size() > 1)
            {
                result += values.top();
                values.pop();
            }

            if (!values.empty())
                values.pop();

            i++;
        }

        return result;
    }
};