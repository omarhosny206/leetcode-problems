
class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        stack<int> values;

        vector<int> minValues(nums.size());
        int minValue = INT_MAX;

        for (int i = 0; i < nums.size(); ++i)
        {
            minValue = min(minValue, nums[i]);
            minValues[i] = minValue;
        }

        for (int j = nums.size() - 1; j >= 0; --j)
        {
            while (!values.empty() && values.top() <= minValues[j])
                values.pop();

            if (!values.empty() && values.top() < nums[j])
                return true;

            values.push(nums[j]);
        }

        return false;
    }
};