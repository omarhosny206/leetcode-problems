// https://leetcode.com/problems/remove-stones-to-minimize-the-total/

class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        int result = 0;
        priority_queue<int> values;

        for (int &pile : piles)
            values.push(pile);

        while (k--)
        {
            int value = values.top();
            values.pop();

            value = (value + 1) / 2;
            values.push(value);
        }

        while (!values.empty())
        {
            result += values.top();
            values.pop();
        }

        return result;
    }
};