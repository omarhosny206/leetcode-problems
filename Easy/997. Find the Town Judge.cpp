// https://leetcode.com/problems/find-the-town-judge/

class Solution
{
public:
    int findJudge(int N, vector<vector<int>> &trust)
    {
        vector<int> freq(N + 1);

        for (vector<int> &pair : trust)
        {
            freq[pair[0]]--;
            freq[pair[1]]++;
        }

        for (int i = 1; i < freq.size(); ++i)
            if (freq[i] == N - 1)
                return i;

        return -1;
    }
};