
class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        unordered_map<int, int> freq;

        for (vector<int> group : trust)
        {
            freq[group[0]]--;
            freq[group[1]]++;
        }

        for (int i = 1; i <= n; ++i)
            if (freq[i] == n - 1)
                return i;

        return -1;
    }
};