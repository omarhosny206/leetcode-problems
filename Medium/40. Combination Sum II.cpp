// https://leetcode.com/problems/combination-sum-ii/

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> currentSum;
        hasSumWithTarget(candidates, result, currentSum, target, 0);
        return result;
    }

    void hasSumWithTarget(vector<int> &candidates, vector<vector<int>> &result, vector<int> &currentSum, int target, int position)
    {
        if (target < 0)
            return;

        if (target == 0)
        {
            result.push_back(currentSum);
            return;
        }

        for (int i = position; i < candidates.size(); i++)
        {
            if (i > position && candidates[i] == candidates[i - 1])
                continue;

            currentSum.push_back(candidates[i]);
            hasSumWithTarget(candidates, result, currentSum, target - candidates[i], i + 1);
            currentSum.pop_back();
        }
    }
};