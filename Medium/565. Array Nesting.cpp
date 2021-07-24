// https://leetcode.com/problems/array-nesting/

class Solution
{
public:
    int arrayNesting(vector<int> &nums)
    {
        int result = 0;
        vector<int> seen(nums.size());

        for (int i = 0; i < nums.size(); ++i)
            if (seen[i] == false)
                result = max(result, DFS(nums, seen, i));

        return result;
    }

    int DFS(vector<int> &nums, vector<int> &seen, int current)
    {
        if (seen[current])
            return 0;

        seen[current] = true;
        return 1 + DFS(nums, seen, nums[current]);
    }
};