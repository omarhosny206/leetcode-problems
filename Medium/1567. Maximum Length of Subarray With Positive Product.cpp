// https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/

class Solution
{
public:
    int getMaxLen(vector<int> &nums)
    {
        int result = 0;
        int positive = 0;
        int negative = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                positive = negative = 0;
            }
            else if (nums[i] > 0)
            {
                positive += 1;

                if (negative != 0)
                    negative += 1;

                result = max(result, positive);
            }
            else
            {
                swap(positive, negative);

                negative += 1;

                if (positive != 0)
                    positive += 1;

                result = max(result, positive);
            }
        }

        return result;
    }
};