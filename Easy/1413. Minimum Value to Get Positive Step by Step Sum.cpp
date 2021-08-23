// https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/

class Solution
{
public:
    int minStartValue(vector<int> &nums)
    {
        int result = 1;
        int sum = 0;

        for (int &num : nums)
        {
            sum += num;

            if (sum <= 0)
                result = max(result, 1 - sum);
        }

        return result;
    }
};