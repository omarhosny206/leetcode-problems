// https://leetcode.com/problems/combination-sum-iii/

class Solution
{
    vector<vector<int>> result;

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        if (k > n)
            return {};

        vector<int> currentSum;
        findCombinations(k, n, 1, currentSum);

        return result;
    }

    void findCombinations(int k, int n, int start, vector<int> &currentSum)
    {
        if (k == 0)
        {
            if (n == 0)
                result.push_back(currentSum);

            return;
        }

        for (int i = start; i <= 9; ++i)
        {
            currentSum.push_back(i);
            findCombinations(k - 1, n - i, i + 1, currentSum);
            currentSum.pop_back();
        }
    }
};