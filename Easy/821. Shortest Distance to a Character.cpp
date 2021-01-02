// https://leetcode.com/problems/shortest-distance-to-a-character/

class Solution
{
public:
    vector<int> shortestToChar(string S, char C)
    {
        vector<int> result(S.length());
        int previous = INT_MIN + 1000;

        for (int i = 0; i < S.length(); ++i)
        {
            if (S[i] == C)
                previous = i;

            result[i] = i - previous;
        }

        previous = INT_MAX - 1000;

        for (int i = S.length() - 1; i >= 0; --i)
        {
            if (S[i] == C)
                previous = i;

            result[i] = min(result[i], previous - i);
        }

        return result;
    }
};