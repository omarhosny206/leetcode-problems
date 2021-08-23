// https://leetcode.com/problems/monotonic-array/

class Solution
{
public:
    bool isMonotonic(vector<int> &nums)
    {
        int first = 0;
        int second = 0;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[i - 1])
                first++;

            else if (nums[i] < nums[i - 1])
                second++;
        }

        return first == 0 || second == 0;
    }
};