// https://leetcode.com/problems/contiguous-array/

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> counts;
        counts[0] = -1;
        int max_length = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
                count--;
            else
                count++;

            if (counts.find(count) != counts.end())
                max_length = max(max_length, i - counts[count]);
            else
                counts[count] = i;
        }

        return max_length;
    }
};