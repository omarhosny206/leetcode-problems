// https://leetcode.com/problems/maximum-product-difference-between-two-pairs/

class Solution
{
public:
    int maxProductDifference(vector<int> &nums)
    {
        int result = 0;
        int firstMax = INT_MIN;
        int secondMax = INT_MIN;
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > firstMax)
            {
                secondMax = firstMax;
                firstMax = nums[i];
            }

            else if (nums[i] > secondMax)
                secondMax = nums[i];

            if (nums[i] < secondMin)
            {
                firstMin = secondMin;
                secondMin = nums[i];
            }

            else if (nums[i] < firstMin)
                firstMin = nums[i];
        }

        result = (firstMax * secondMax) - (firstMin * secondMin);

        return result;
    }
};