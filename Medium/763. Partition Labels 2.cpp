// https://leetcode.com/problems/partition-labels/

class Solution
{
public:
    vector<int> partitionLabels(string S)
    {
        vector<int> result;
        vector<int> lastPosition(26);
        vector<bool> visited(26);
        int start = 0;

        int counter = 0;
        int uniqueLetters = 0;

        for (int i = 0; i < S.length(); ++i)
            lastPosition[S[i] - 'a'] = i;

        for (int i = 0; i < S.length(); ++i)
        {
            if (i == lastPosition[S[i] - 'a'])
                counter++;

            if (!visited[S[i] - 'a'])
            {
                uniqueLetters++;
                visited[S[i] - 'a'] = true;
            }

            if (counter == uniqueLetters)
            {
                result.push_back(i - start + 1);
                start = i + 1;
                counter = 0;
                uniqueLetters = 0;
            }
        }

        return result;
    }
};