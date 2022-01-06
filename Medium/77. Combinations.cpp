// https://leetcode.com/problems/combinations/

class Solution
{
    vector<vector<int>> combinations;

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> currentCombination;
        findCombinations(currentCombination, n, k, 1);
        return combinations;
    }

    void findCombinations(vector<int> &currentCombination, int n, int k, int start)
    {
        if (start > n + 1)
            return;

        if (currentCombination.size() == k)
        {
            combinations.push_back(currentCombination);
            return;
        }

        for (int i = start; i <= n; i++)
        {
            currentCombination.push_back(i);
            findCombinations(currentCombination, n, k, i + 1);
            currentCombination.pop_back();
        }
    }
};