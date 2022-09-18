// https://leetcode.com/problems/trapping-rain-water/

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int result = 0;
        int i = 0;
        int j = height.size() - 1;

        int maxValue = INT_MIN;
        int minValue = INT_MAX;

        while (i <= j)
        {
            minValue = min(height[i], height[j]);
            maxValue = max(maxValue, minValue);

            result += maxValue - minValue;

            if (height[i] < height[j])
                i++;

            else
                j--;
        }

        return result;
    }
};