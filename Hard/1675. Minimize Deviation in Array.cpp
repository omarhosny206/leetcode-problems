// https://leetcode.com/problems/minimize-deviation-in-array/

class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        int minDeviation = INT_MAX;
        int minValue = INT_MAX;

        priority_queue<int> values;

        for (int &num : nums)
        {
            if (num % 2 != 0)
                num *= 2;

            values.push(num);
            minValue = min(minValue, num);
        }

        while ((values.top()) % 2 == 0)
        {
            int maxValue = values.top();
            values.pop();

            minDeviation = min(minDeviation, maxValue - minValue);

            maxValue /= 2;
            values.push(maxValue);
            minValue = min(minValue, maxValue);
        }

        minDeviation = min(minDeviation, values.top() - minValue);

        return minDeviation;
    }
};