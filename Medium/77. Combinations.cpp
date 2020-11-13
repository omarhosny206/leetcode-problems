// https://leetcode.com/problems/combinations/

class Solution
{
    vector<int> comb;

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> combinations;
        findCombinations(combinations, n, k, 1);
        return combinations;
    }

    void findCombinations(vector<vector<int>> &combinations, int n, int k, int index)
    {
        if (comb.size() == k)
        {
            combinations.push_back(comb);
            return;
        }

        if (index > n)
            return;

        for (int i = index; i <= n; i++)
        {
            comb.push_back(i);
            findCombinations(combinations, n, k, i + 1);
            comb.pop_back();
        }
    }
};