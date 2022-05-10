
class Solution
{
    vector<vector<int>> result;

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> current;
        dfs(k, n, current, 0, 1);
        return result;
    }

    void dfs(int k, int n, vector<int> &current, int currentSum, int index)
    {
        if (currentSum > n)
            return;

        if (current.size() == k && currentSum == n)
        {
            result.push_back(current);
            return;
        }

        for (int i = index; i <= 9; ++i)
        {
            if (find(current.begin(), current.end(), i) == current.end())
            {
                current.push_back(i);
                dfs(k, n, current, currentSum + i, i + 1);
                current.pop_back();
            }
        }
    }
};