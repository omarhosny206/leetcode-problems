// https://leetcode.com/problems/find-the-town-judge/

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        unordered_map<int, int> freq;

        for (vector<int> &pair : trust)
        {
            freq[pair[0]]--;
            freq[pair[1]]++;
        }

        for (int i = 1; i <= n; ++i)
            if (freq[i] == n - 1)
                return i;

        return -1;
    }
};