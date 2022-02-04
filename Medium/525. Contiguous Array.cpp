// https://leetcode.com/problems/contiguous-array/

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int result = 0;
        unordered_map<int, int> position;
        int sum = 0;

        position[0] = -1;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
                sum--;

            else
                sum++;

            if (position.find(sum) != position.end())
                result = max(result, i - position[sum]);

            else
                position[sum] = i;
        }

        return result;
    }
};