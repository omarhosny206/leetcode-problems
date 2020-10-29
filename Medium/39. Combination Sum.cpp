// https://leetcode.com/problems/combination-sum/

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
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
            result.push_back(currentSum);

        for (int i = position; i < candidates.size(); i++)
        {
            currentSum.push_back(candidates[i]);
            hasSumWithTarget(candidates, result, currentSum, target - candidates[i], i);
            currentSum.pop_back();
        }
    }
};