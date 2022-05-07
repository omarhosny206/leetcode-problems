// https://leetcode.com/problems/132-pattern/

class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        stack<int> values;
        int thirdElement = INT_MIN;

        for (int i = nums.size() - 1; i >= 0; --i)
        {
            if (nums[i] < thirdElement)
                return true;

            while (!values.empty() && values.top() < nums[i])
            {
                thirdElement = values.top();
                values.pop();
            }

            values.push(nums[i]);
        }

        return false;
    }
};