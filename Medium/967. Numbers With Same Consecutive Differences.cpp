// https://leetcode.com/problems/numbers-with-same-consecutive-differences/

class Solution
{
    vector<int> result;

public:
    vector<int> numsSameConsecDiff(int n, int k)
    {
        for (int i = 1; i <= 9; ++i)
            dfs(n - 1, k, i, i);

        return result;
    }

    void dfs(int n, int k, int i, int current)
    {
        if (n == 0)
        {
            result.push_back(current);
            return;
        }

        if (i + k <= 9)
        {
            int temp = current * 10 + (i + k);
            dfs(n - 1, k, i + k, temp);
        }

        if (i - k >= 0 && k != 0)
        {
            int temp = current * 10 + (i - k);
            dfs(n - 1, k, i - k, temp);
        }
    }
};