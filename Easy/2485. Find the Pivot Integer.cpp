// https://leetcode.com/problems/find-the-pivot-integer/

class Solution
{
public:
    int pivotInteger(int n)
    {
        if (n == 1)
            return 1;

        vector<int> prefixSum(n + 1);
        prefixSum[1] = 1;

        for (int i = 2; i <= n; ++i)
            prefixSum[i] += i + prefixSum[i - 1];

        for (int i = 1; i <= n; ++i)
            if (prefixSum[n] - prefixSum[i] == prefixSum[i - 1])
                return i;

        return -1;
    }
};