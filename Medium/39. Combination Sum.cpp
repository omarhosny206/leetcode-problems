// https://leetcode.com/problems/combination-sum/

class Solution
{
    vector<vector<int>> result;
    vector<int> combination;

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        dfs(candidates, target, 0, 0);
        return result;
    }

    void dfs(vector<int> &candidates, int target, int currentSum, int position)
    {
        if (currentSum > target)
        {
            return;
        }

        if (currentSum == target)
        {
            result.push_back(combination);
            return;
        }

        for (int i = position; i < candidates.size(); ++i)
        {
            combination.push_back(candidates[i]);
            dfs(candidates, target, currentSum + candidates[i], i);
            combination.pop_back();
        }
    }
};