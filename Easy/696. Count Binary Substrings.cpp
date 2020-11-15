// https://leetcode.com/problems/count-binary-substrings/

class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        vector<int> groups(s.length());
        groups[0] = 1;

        int t = 0;
        for (int i = 1; i < s.length(); ++i)
        {
            if (s[i] == s[i - 1])
                groups[t]++;
            else
                groups[++t] = 1;
        }

        int answer = 0;
        for (int i = 1; i <= t; ++i)
            answer += min(groups[i], groups[i - 1]);

        return answer;
    }
};
