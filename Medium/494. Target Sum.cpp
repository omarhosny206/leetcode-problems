// https://leetcode.com/problems/target-sum/

class Solution
{
    int DP[21][2001];

public:
    int findTargetSumWays(vector<int> &nums, int S)
    {
        memset(DP, 0, sizeof(DP[0][0]) * 21 * 2001);

        long long sum = accumulate(nums.begin(), nums.end(), 0);
        long long sumToCheck = (sum + S) / 2;

        if (S > sum || (sum + S) % 2 == 1)
            return 0;

        return countSubsetsWithSum(nums, sumToCheck);
    }

    int countSubsetsWithSum(vector<int> &nums, long long sumToCheck)
    {
        int i, j;
        int n = nums.size();

        for (i = 0; i < n + 1; i++)
        {
            for (j = 0; j < sumToCheck + 1; j++)
            {
                if (i == 0)
                    DP[i][j] = 0;
                if (j == 0)
                    DP[i][j] = 1;
            }
        }

        for (i = 1; i < n + 1; i++)
        {
            for (j = 0; j < sumToCheck + 1; j++)
            {
                if (nums[i - 1] <= j)
                    DP[i][j] = DP[i - 1][j] + DP[i - 1][j - nums[i - 1]];
                else
                    DP[i][j] = DP[i - 1][j];
            }
        }

        return DP[n][sumToCheck];
    }
};