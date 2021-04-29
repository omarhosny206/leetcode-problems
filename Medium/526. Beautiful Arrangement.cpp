// https://leetcode.com/problems/beautiful-arrangement/

class Solution
{
    int result = 0;

public:
    int countArrangement(int n)
    {
        vector<int> nums(n);

        for (int i = 1; i <= n; i++)
            nums[i - 1] = i;

        DFS(nums, n, 0);
        return result;
    }

    void DFS(vector<int> &nums, int n, int index)
    {
        if (index == n)
        {
            result++;
            return;
        }

        for (int i = index; i < n; i++)
        {
            if ((index + 1) % nums[i] == 0 || nums[i] % (index + 1) == 0)
            {
                swap(nums[i], nums[index]);
                DFS(nums, n, index + 1);
                swap(nums[i], nums[index]);
            }
        }
    }
};