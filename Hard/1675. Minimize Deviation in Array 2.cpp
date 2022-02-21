// https://leetcode.com/problems/minimize-deviation-in-array/

class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        int minDeviation = INT_MAX;
        int minValue = INT_MAX;

        set<int> values;

        for (int &num : nums)
        {
            if (num % 2 != 0)
                num *= 2;

            values.insert(num);
        }

        minValue = *values.begin();

        while ((*values.rbegin()) % 2 == 0)
        {
            int maxValue = *values.rbegin();
            values.erase(*values.rbegin());

            minDeviation = min(minDeviation, maxValue - minValue);

            maxValue /= 2;
            values.insert(maxValue);
            minValue = min(minValue, maxValue);
        }

        minDeviation = min(minDeviation, *values.rbegin() - minValue);

        return minDeviation;
    }
};