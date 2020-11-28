// https://leetcode.com/problems/target-sum/

class Solution
{
    int DP[21][2001];

public:
    int DFS(int index, vector<int> &nums, int &S, int sum)
    {
        if (index == nums.size())
            return sum == S ? 1 : 0;

        if (DP[index][sum + 1000] != -1)
            return DP[index][sum + 1000];

        int count = 0;

        count += DFS(index + 1, nums, S, sum + nums[index]);
        count += DFS(index + 1, nums, S, sum - nums[index]);

        return DP[index][sum + 1000] = count;
    }

    int findTargetSumWays(vector<int> &nums, int S)
    {
        memset(DP, -1, sizeof(DP));
        return DFS(0, nums, S, 0);
    }
};
