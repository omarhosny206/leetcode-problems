// https://leetcode.com/problems/largest-substring-between-two-equal-characters/

class Solution
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        vector<int> seen(26, -1);
        int result = -1;

        for (int i = 0; i < s.length(); ++i)
        {
            if (seen[s[i] - 'a'] == -1)
                seen[s[i] - 'a'] = i;

            else
                result = max(result, i - seen[s[i] - 'a'] - 1);
        }

        return result;
    }
};