class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> freq(n + 1);

        for (vector<int> &pair : trust)
        {
            freq[pair[0]]--;
            freq[pair[1]]++;
        }

        for (int i = 1; i < freq.size(); ++i)
            if (freq[i] == n - 1)
                return i;

        return -1;
    }
};