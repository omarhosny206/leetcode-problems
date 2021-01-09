// https://leetcode.com/problems/next-greater-element-ii/

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        vector<int> result(nums.size(), -1);
        stack<int> indices;
        int size = nums.size();

        for (int i = 0; i < nums.size() * 2; ++i)
        {
            while (!indices.empty() && nums[indices.top()] < nums[i % size])
            {
                result[indices.top()] = nums[i % size];
                indices.pop();
            }

            if (i < size)
                indices.push(i);
        }

        return result;
    }
};