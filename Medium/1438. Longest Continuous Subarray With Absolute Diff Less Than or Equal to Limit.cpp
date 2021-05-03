// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

class Solution
{
    deque<int> maxValues;
    deque<int> minValues;

public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        int result = 1;
        int i = 0;

        for (int j = 0; j < nums.size(); ++j)
        {
            push(nums[j]);

            int maxValue = maxValues.front();
            int minValue = minValues.front();

            if (maxValue - minValue <= limit)
                result = max(result, j - i + 1);

            else
            {
                pop(nums[i]);
                ++i;
            }
        }

        return result;
    }

    void push(int num)
    {
        while (!minValues.empty() && minValues.back() > num)
            minValues.pop_back();

        minValues.push_back(num);

        while (!maxValues.empty() && maxValues.back() < num)
            maxValues.pop_back();

        maxValues.push_back(num);
    }

    void pop(int num)
    {
        if (minValues.front() == num)
            minValues.pop_front();

        if (maxValues.front() == num)
            maxValues.pop_front();
    }
};