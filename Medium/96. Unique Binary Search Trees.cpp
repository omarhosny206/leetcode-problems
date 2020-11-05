// https://leetcode.com/problems/unique-binary-search-trees/

class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> table(n + 1, 0);
        table[0] = 1;
        table[1] = 1;

        for (int i = 2; i <= n; ++i)
            for (int j = 0; j < i; ++j)
                table[i] += table[j] * table[i - j - 1];

        return table[n];
    }
};