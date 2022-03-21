// https://leetcode.com/problems/partition-labels/

class Solution
{
public:
    vector<int> partitionLabels(string S)
    {
        vector<int> result;
        vector<int> lastPosition(26);
        int start = 0;
        int end = 0;

        for (int i = 0; i < S.length(); ++i)
            lastPosition[S[i] - 'a'] = i;

        for (int i = 0; i < S.length(); ++i)
        {
            end = max(end, lastPosition[S[i] - 'a']);

            if (i == end)
            {
                result.push_back(i - start + 1);
                start = i + 1;
            }
        }

        return result;
    }
};