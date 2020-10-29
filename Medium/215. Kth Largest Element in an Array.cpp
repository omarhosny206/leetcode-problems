// https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {

        priority_queue<int, vector<int>, greater<int>> numbers;

        for (int i = 0; i < nums.size(); i++)
        {
            numbers.push(nums[i]);
            if (numbers.size() > k)
                numbers.pop();
        }

        return numbers.top();
    }
};